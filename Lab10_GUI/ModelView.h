#pragma once
#include <iostream>
#include <Qt>
#include <vector>
#include <qabstractitemmodel.h>
#include "Film.h"

using std::vector;
class ModelView :public QAbstractTableModel {
	vector<Film> films;
public:
	ModelView(const vector<Film>& films):films{films}{}
	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return films.size();
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 4;
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		qDebug() << "row:" << index.row() << " col:" << index.column() << " role" << role;
		if (role == Qt::DisplayRole) {
			Film f = films[index.row()];
			if (index.column() == 0) {
				return QString::fromStdString(f.getTitlu());
			}
			else if (index.column() == 1) {
				return QString::fromStdString(f.getGen());
			}
			else if (index.column() == 2) {
				return QString::number(f.getAn());

			}
			else if (index.column() == 3) {
				return QString::fromStdString(f.getActor());
			}
		}		
		
		if (role == Qt::BackgroundRole) {
			QBrush bg{ Qt::magenta };
			return bg;

		}

		if (role == Qt::FontRole) {
			QFont f{ "Verdana",18 };
			return f;
		}
		return QVariant{};
		
		//return QString("Row%1, Column%2").arg(index.row() + 1).arg(
		//	index.column() + 1);
	}

	void setFilm(const vector<Film> films) {
		this->films = films;
		auto topStanga = createIndex(0, 0);
		auto josDr = createIndex(rowCount(), columnCount());
		emit dataChanged(topStanga, josDr);
	}

	QVariant headerData(int section, Qt::Orientation orient, int role) const  {
		

		
		if (role == Qt::DisplayRole) {
			if(orient==Qt::Horizontal){
			switch (section)
			{
			case 0:
				return tr("Titlu:");
			case 1:
				return tr("Gen:");
			case 2:
				return tr("An:");
			case 3:
				return tr("Actor");
			default:
				return QString("");
			}
			}
		}
		return QVariant{};
	}

	Qt::ItemFlags flags(const QModelIndex&) const {
		return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
	}
};