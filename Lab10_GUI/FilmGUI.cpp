#include "FilmGUI.h"

void FilmGUI::initcompGUI()
{
	//main = new QMainWindow;
	

	QHBoxLayout* mainLy = new QHBoxLayout;
	this->setLayout(mainLy);
	//main->setLayout(mainLy);
	QWidget* left = new QWidget;
	QVBoxLayout* leftLy = new QVBoxLayout;
	left->setLayout(leftLy);

	QWidget* form = new QWidget;
	QFormLayout* formLy = new QFormLayout;
	form->setLayout(formLy);
	editTitlu = new QLineEdit;
	editGen = new QLineEdit;
	editAn = new QLineEdit;
	editActor = new QLineEdit;

	formLy->addRow(lblTitlu, editTitlu);
	formLy->addRow(lblGen, editGen);
	formLy->addRow(lblAn, editAn);
	formLy->addRow(lblActor, editActor);

	addFilm = new QPushButton("Adauga film");
	formLy->addWidget(addFilm);
	
	leftLy->addWidget(form);

	QVBoxLayout* radioBLy = new QVBoxLayout;
	this->sortType->setLayout(radioBLy);
	radioBLy->addWidget(sortbyActor);
	radioBLy->addWidget(sortbyAn);
	radioBLy->addWidget(sortbyTitlu);

	sortFilm = new QPushButton("Sorteaza");
	radioBLy->addWidget(sortFilm);
	leftLy->addWidget(sortType);

	
	
	//Meniul de filtrare
	QHBoxLayout* filter = new QHBoxLayout;
	
	QWidget* filterLeft = new QWidget;
	QVBoxLayout* filterLyLeft = new QVBoxLayout;
	filterLeft->setLayout(filterLyLeft);
	editfilterTitlu = new QLineEdit;
	filterLyLeft->addWidget(lblfilterTitlu);
	filterLyLeft->addWidget(editfilterTitlu);
	filterFilmTitlu = new QPushButton("Filtreaza dupa titlu");
	filterLyLeft->addWidget(filterFilmTitlu);
	filter->addWidget(filterLeft);
	//leftLy->addWidget(filterLeft);
	
	QWidget* filterRight = new QWidget;
	QVBoxLayout* filterLyRight = new QVBoxLayout;
	filterRight->setLayout(filterLyRight);
	editfilterAn = new QLineEdit;
	filterLyRight->addWidget(lblfilterAn);
	filterLyRight->addWidget(editfilterAn);
	filterFilmAn = new QPushButton("Filtreaza dupa an");
	filterLyRight->addWidget(filterFilmAn);
	
	filter->addWidget(filterRight);	
	leftLy->addLayout(filter);
	
	QGroupBox* cosMenu = new QGroupBox("Cos");
	QVBoxLayout* cosLy = new QVBoxLayout;
	cosMenu->setLayout(cosLy);
	viewCos  = new QPushButton("Vizualizare cos");
	viewPainCos = new QPushButton("Vizualizare cos abstract");
	//nrOfCos = new QLabel("Numarul de filme din cos: ");
	cosLy->addWidget(viewCos);
	cosLy->addWidget(viewPainCos);
	//cosLy->addWidget(nrOfCos);
	leftLy->addWidget(cosMenu);


	//Tabelul cu filmele din aplicatie
	QWidget* right = new QWidget;
	QVBoxLayout* rightLy = new QVBoxLayout;
	right->setLayout(rightLy);

	int nLines = 10;
	int nColoane = 4;
	this->Filmtable = new QTableWidget{ nLines,nColoane };

	QStringList tblHead;
	tblHead << "Titlul" << "Gen" << "An" << "Actor";
	this->Filmtable->setHorizontalHeaderLabels(tblHead);
	this->Filmtable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	//this->Filmtable->resizeColumnsToContents();
	rightLy->addWidget(Filmtable);
	


	//Update and Delet buttons
	update = new QPushButton("Modifica");
	deleteFilm = new QPushButton("Sterge");
	addtocos = new QPushButton("Adauga in cos");
	QWidget* upd_del = new QWidget;
	QHBoxLayout* upd_delLy = new QHBoxLayout;
	upd_del->setLayout(upd_delLy);
	upd_delLy->addWidget(update);
	upd_delLy->addWidget(deleteFilm);
	upd_delLy->addWidget(addtocos);
	rightLy->addWidget(upd_del);


	//Undo Buttons
	undoAdd = new QPushButton("Adaugare");
	undoDel = new QPushButton("Stergere");
	undoMod = new QPushButton("Modificare");
	//QWidget* undo = new QWidget;
	QHBoxLayout* undoLy = new QHBoxLayout;
	lblUndo->setLayout(undoLy);
	undoLy->addWidget(lblUndo);
	undoLy->addWidget(undoAdd);
	undoLy->addWidget(undoDel);
	undoLy->addWidget(undoMod);
	rightLy->addWidget(lblUndo);

	mainLy->addWidget(left);
	mainLy->addWidget(right);
	mainLy->addWidget(tableVw);
	
	//cos = new QWidget;
	//QHBoxLayout* cosLy1 = new QHBoxLayout;
	//cos->setLayout(cosLy1);

	//QWidget* left1 = new QWidget;
	//QVBoxLayout* leftLy1 = new QVBoxLayout;
	//left1->setLayout(leftLy1);


	//QGroupBox* randomBox = new QGroupBox();
	//QVBoxLayout* randLy = new QVBoxLayout;
	//randomBox->setLayout(randLy);
	//QLabel* lblRand = new QLabel("Cate filme doriti sa adaugati:");
	//randLy->addWidget(lblRand);
	//numbrt = new QDoubleSpinBox;
	//numbrt->setSingleStep(1);
	//numbrt->setRange(1.0, double(serv.getFilme().size()));
	//randLy->addWidget(numbrt);
	//addrandom = new QPushButton("Adauga");
	//randLy->addWidget(addrandom);
	//goleste = new QPushButton("Goleste");
	//leftLy1->addWidget(randomBox);
	//go_fisier = new QPushButton("Export");
	//leftLy1->addWidget(goleste);
	//leftLy1->addWidget(go_fisier);
	//cosLy1->addWidget(left1);
	//

	//QWidget* right1 = new QWidget;
	//QVBoxLayout* rightLy1 = new QVBoxLayout;
	//right1->setLayout(rightLy1);

	//int nLines1 = 10;
	//int nColoane1 = 4;
	//this->FilmtableCos = new QTableWidget{ nLines1,nColoane1 };

	//QStringList tblHead1;
	//tblHead1 << "Titlul" << "Gen" << "An" << "Actor";
	//this->FilmtableCos->setHorizontalHeaderLabels(tblHead1);
	//this->FilmtableCos->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	////this->Filmtable->resizeColumnsToContents();
	//rightLy1->addWidget(FilmtableCos);

	//cosLy1->addWidget(right1);
}

void FilmGUI::connectSlots()
{
	QObject::connect(addFilm, &QPushButton::clicked, this, &FilmGUI::GUIaddFilm);

	QObject::connect(sortFilm, &QPushButton::clicked, [&]() {
		if (this->sortbyTitlu->isChecked())
			reloadFilmList(serv.sortTitlu());
		else if (this->sortbyAn->isChecked())
			reloadFilmList(serv.sortAn());
		else reloadFilmList(serv.sortActor());
		});

	QObject::connect(filterFilmTitlu, &QPushButton::clicked, [&]() {
		string titlu = editfilterTitlu->text().toStdString();
		reloadFilmList(serv.filter_by_titlu(titlu));
		});
	QObject::connect(filterFilmAn, &QPushButton::clicked, [&]() {
		int an = editfilterAn->text().toInt();
		reloadFilmList(serv.filter_by_an(an));
		});
	QObject::connect(Filmtable, &QTableWidget::itemSelectionChanged, [&]() {
		int index = this->get_index();
		auto elms = serv.getFilme();
		if (index >= elms.size()) {
			//cout << "im here" << index << std::endl;
			editTitlu->clear();
			editActor->clear();
			editAn->clear();
			editGen->clear();
		}
		auto elem = elms.at(index);
		editTitlu->setText(QString::fromStdString(elem.getTitlu()));
		editGen->setText(QString::fromStdString(elem.getGen()));
		editActor->setText(QString::fromStdString(elem.getActor()));
		editAn->setText(QString::fromStdString(std::to_string(elem.getAn())));
		});

	QObject::connect(update, &QPushButton::clicked, [&]() {
		int index = this->get_index();
		vector<Film> elms = serv.getFilme();
		Film elem = elms.at(index);
		int an = editAn->text().toInt();
		string gen = editGen->text().toStdString();
		string actor = editActor->text().toStdString();
		serv.modify_film(elem.getTitlu(), gen, an, actor);
		reloadFilmList(serv.getFilme());
		});
	QObject::connect(deleteFilm, &QPushButton::clicked, [&]() {
		int index = this->get_index();
		vector<Film> elms = serv.getFilme();
		Film elem = elms.at(index);
		serv.delete_film(elem.getTitlu());
		reloadFilmList(serv.getFilme());
		});

	QObject::connect(undoAdd, &QPushButton::clicked, [&]() {
		serv.addUndo.doUndo();
		reloadFilmList(serv.getFilme());
		});
	QObject::connect(undoDel, &QPushButton::clicked, [&]() {
		serv.delUndo.doUndo();
		reloadFilmList(serv.getFilme());
		});
	QObject::connect(undoMod, &QPushButton::clicked, [&]() {
		serv.modUndo.doUndo();
		reloadFilmList(serv.getFilme());
		});
	QObject::connect(viewCos, &QPushButton::clicked, [&]() {
		//cos->show() ;
		auto co =new CosGUI{ coss,serv };
		rcp.push_back(co);
		co->show();
		
		});
	QObject::connect(viewPainCos, &QPushButton::clicked, [&]() {
		//cos->show() ;
		auto co = new PaintGUI{ coss ,serv};
		rcp1.push_back(co);
		co->show();

		});
	QObject::connect(addtocos, &QPushButton::clicked, [&]() {
		int index = this->get_index();
		vector<Film> elms = serv.getFilme();
		Film elem = elms.at(index);
		serv.addFilmToCos(elem.getTitlu(),elem.getGen());
		
		//reloadCosList(serv.getCos());
		});
	//QObject::connect(addrandom, &QPushButton::clicked,this, [&]() {
	//	//QMessageBox::information(this, "Info", "Selection changed");
	//	int size = numbrt->value();
	//	serv.addRandom(size);
	//	reloadCosList(serv.getCos());
	//	});
	//QObject::connect(goleste, &QPushButton::clicked, [&]() {
	//	serv.clearCos();
	//	reloadCosList(serv.getCos());
	//	});
	//QObject::connect(go_fisier, &QPushButton::clicked, [&]() {
	//	serv.save_to_a_file("cos.cvs", serv.getCos());
	//	});
}

void FilmGUI::reloadFilmList(vector<Film> films)
{
	Filmtable->clear();
	Filmtable->setRowCount(films.size());
	int nline = 0;
	for (auto& film : films) {
		this->Filmtable->setItem(nline, 0, new QTableWidgetItem(QString::fromStdString(film.getTitlu())));
		this->Filmtable->setItem(nline, 1, new QTableWidgetItem(QString::fromStdString(film.getGen())));
		this->Filmtable->setItem(nline, 2, new QTableWidgetItem(QString::number(film.getAn())));
		this->Filmtable->setItem(nline, 3, new QTableWidgetItem(QString::fromStdString(film.getActor())));
		nline++;
	}

}

void FilmGUI::reloadCosList(vector<Film> films)
{
	this->model->setFilm(films);
}

void FilmGUI::initCos()
{
	//cosW = new QWindow;


	//cos->show();
}

void FilmGUI::GUIaddFilm()
{
	string titlu = editTitlu->text().toStdString();
	string gen = editGen->text().toStdString();
	int an = editAn->text().toInt();
	string actor = editActor->text().toStdString();

	editTitlu->clear();
	editActor->clear();
	editAn->clear();
	editGen->clear();

	this->serv.addFilm(titlu, gen, an, actor);
	this->reloadFilmList(this->serv.getFilme());
}

void CosGUI::initcompGUI()
{
	//cos = new QWidget;
	QHBoxLayout* cosLy1 = new QHBoxLayout;
	this->setLayout(cosLy1);

	QWidget* left1 = new QWidget;
	QVBoxLayout* leftLy1 = new QVBoxLayout;
	left1->setLayout(leftLy1);


	QGroupBox* randomBox = new QGroupBox();
	QVBoxLayout* randLy = new QVBoxLayout;
	randomBox->setLayout(randLy);
	QLabel* lblRand = new QLabel("Cate filme doriti sa adaugati:");
	randLy->addWidget(lblRand);
	numbrt = new QDoubleSpinBox;
	numbrt->setSingleStep(1);
	numbrt->setRange(1.0, double(serv.getFilme().size()));
	randLy->addWidget(numbrt);
	addrandom = new QPushButton("Adauga");
	randLy->addWidget(addrandom);
	goleste = new QPushButton("Goleste");
	leftLy1->addWidget(randomBox);
	go_fisier = new QPushButton("Export");
	leftLy1->addWidget(goleste);
	leftLy1->addWidget(go_fisier);
	cosLy1->addWidget(left1);
	QWidget* right1 = new QWidget;
	QVBoxLayout* rightLy1 = new QVBoxLayout;
	right1->setLayout(rightLy1);

	int nLines1 = 10;
	int nColoane1 = 4;
	this->FilmtableCos = new QTableWidget{ nLines1,nColoane1 };

	QStringList tblHead1;
	tblHead1 << "Titlul" << "Gen" << "An" << "Actor";
	this->FilmtableCos->setHorizontalHeaderLabels(tblHead1);
	this->FilmtableCos->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	//this->Filmtable->resizeColumnsToContents();
	rightLy1->addWidget(FilmtableCos);
	cosLy1->addWidget(right1);
}

void CosGUI::connectSlots() {

	QObject::connect(addrandom, &QPushButton::clicked, this, [&]() {
		//QMessageBox::information(this, "Info", "Selection changed");
		int size = numbrt->value();
		serv.addRandom(size);
		reloadCosList(serv.getCos());
		});
	QObject::connect(goleste, &QPushButton::clicked, [&]() {
		serv.clearCos();
		reloadCosList(serv.getCos());
		});
	QObject::connect(go_fisier, &QPushButton::clicked, [&]() {
		serv.save_to_a_file("cos.cvs", serv.getCos());
		});
}

void CosGUI::reloadCosList(vector<Film> films) {
	FilmtableCos->clearContents();
	FilmtableCos->setRowCount(films.size());
	int nline = 0;
	for (auto& film : films) {
		this->FilmtableCos->setItem(nline, 0, new QTableWidgetItem(QString::fromStdString(film.getTitlu())));
		this->FilmtableCos->setItem(nline, 1, new QTableWidgetItem(QString::fromStdString(film.getGen())));
		this->FilmtableCos->setItem(nline, 2, new QTableWidgetItem(QString::number(film.getAn())));
		this->FilmtableCos->setItem(nline, 3, new QTableWidgetItem(QString::fromStdString(film.getActor())));
		nline++;
	}

}
