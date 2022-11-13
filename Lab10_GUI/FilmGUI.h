#pragma once
#include <vector>
#include <string>
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QHeaderView>
#include <QGroupBox>
#include <QRadioButton>
#include <QWindow>
#include <QMainWindow>
#include <QDoubleSpinBox>
#include <qpainter.h>
#include "observer.h"
#include "ctime"
#include "Service.h"
#include "ModelView.h"

using std::vector;
using std::string;

class CosGUI:public QWidget,public Observer
{
	Cos& coss;

	Service& serv;

	QTableWidget* FilmtableCos;
	//QPushButton* viewCos;
	QLabel* nrOfCos;
	QPushButton* addrandom;
	QDoubleSpinBox* numbrt;
	QPushButton* goleste;
	QPushButton* go_fisier;
	QWidget* cos;

	void initcompGUI();

	void connectSlots();
	void reloadCosList(vector<Film> films);
	void update() override {
		reloadCosList(coss.getCos());
	}
public:
	CosGUI(Cos& c, Service& s) :coss{ c },serv { s } {
		coss.addObs(this);
		initcompGUI();
		connectSlots();
		reloadCosList(serv.getCos());
	}
	~CosGUI() {
		coss.rmObs(this);
	}
};

class PaintGUI : public QWidget, public Observer {
private:
	Cos& cos;
	Service& serv;
public:
	PaintGUI(Cos& rep, Service& serv) :cos{ rep }, serv{ serv } {
		rep.addObs(this);
	}

	void paintEvent(QPaintEvent*) override {
		QPainter p{ this };
		int x;
		int y;
		int ind = 1;
		for (auto& it : serv.getCos()) {
			//p.drawRect(x, y, 10, song.getDurata() * 10);
			srand((unsigned)time(0));
			x = (rand()*ind) % 200 + 1;
			y = (rand()*ind) % 200 + 1;	
			QPointF p1(x,y);
			//qDebug() << x << " " << y;
			QRectF target(x, y, 100, 94);
			QRectF source(0, 0, 732, 720);
			QImage image("arta.jpg");
			//p.drawLine(0, 0, width(), height());
			//p.drawImage(x, y,	image);
			if (ind % 1 == 0) {
			qreal x1 = (rand() * ind) % 400 + 1;
			qreal x2 = (rand() * ind )% 400 + 1;
			p.drawEllipse(p1, x1,x2);
			}
			else {
				static const QPointF points[4] = {

					QPointF((rand() * ind) % 400 + 1,(rand() * ind) % 400 + 1),
					QPointF((rand() * ind) % 400 + 1,(rand() * ind) % 400 + 1),
					QPointF((rand() * ind) % 400 + 1, (rand() * ind) % 400 + 1),
					QPointF((rand() * ind) % 400 + 1, (rand() * ind) % 400 + 1)
				};
				p.drawPolygon(points, 4);
			}
			ind++;

		}
	}

	void update() override {
		repaint();
	}

	~PaintGUI() {
		cos.rmObs(this);
	}
};
class FilmGUI :public QWidget{
private:
	Service& serv;
	Cos coss;
	//QMainWindow* main;

	QLabel* lblTitlu = new QLabel{ "Titlul  filmului este:" };
	QLabel* lblGen = new QLabel{ "Genul filmulu este: " };
	QLabel* lblAn = new QLabel{ "Anul aparitiei filmului este:" };
	QLabel* lblActor = new QLabel{ "Actorul principal:" };

	QLineEdit* editTitlu;
	QLineEdit* editGen;
	QLineEdit* editAn;
	QLineEdit* editActor;
	
	QPushButton* addFilm;

	QGroupBox* sortType = new QGroupBox(tr("Tip sortare"));
	QRadioButton* sortbyTitlu = new QRadioButton(QString::fromStdString("Titlu"));
	QRadioButton* sortbyAn = new QRadioButton(QString::fromStdString("An"));
	QRadioButton* sortbyActor = new QRadioButton(QString::fromStdString("Actor"));
	QPushButton* sortFilm;

	QGroupBox* fiterType = new QGroupBox(tr("Tip filtrare"));
	QLabel* lblfilterTitlu = new QLabel("Titlul dupa care se filtraeaza:");
	QLineEdit* editfilterTitlu;
	QPushButton* filterFilmTitlu;

	QLabel* lblfilterAn= new QLabel("Anul dupa care se filtraeaza:");
	QLineEdit* editfilterAn;
	QPushButton* filterFilmAn;

	QTableWidget* Filmtable;

	QPushButton* update;
	QPushButton* deleteFilm;
	QPushButton* addtocos;

	QGroupBox * lblUndo = new QGroupBox(tr("Undo"));
	QPushButton* undoAdd;
	QPushButton* undoDel;
	QPushButton* undoMod;


	QTableWidget* FilmtableCos;
	QPushButton* viewCos;
	QPushButton* viewPainCos;
	QLabel* nrOfCos;
	QPushButton* addrandom ;
	QDoubleSpinBox* numbrt;
	QPushButton* goleste ;
	QPushButton* go_fisier;
	QWidget* cos;
	//QWindow* cosW;
	ModelView* model;
	QTableView* tableVw = new QTableView;

	void initcompGUI();

	void connectSlots();
	void reloadFilmList(vector<Film> films);
	void reloadCosList(vector<Film> films);
	void initCos();
	vector<CosGUI*> rcp;
	vector<PaintGUI*> rcp1;
public:
	FilmGUI(Service& srv) : serv { srv } {
		initcompGUI();
		this->model = new ModelView{ srv.getFilme() };
		tableVw->setModel(model);
		connectSlots();
		reloadFilmList(serv.getFilme());
		reloadCosList(serv.getFilme());
		initCos();
		rcp.push_back(new CosGUI{ coss,serv });
		//rcp[0]->show();
		//main->show();
	}
	void GUIaddFilm();
	int get_index() {
		//returneaza indexul curent din lista
	    auto current_index = this->Filmtable->selectionModel()->currentIndex();
		return current_index.row();
	}
};
