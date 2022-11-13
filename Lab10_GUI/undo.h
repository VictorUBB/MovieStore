#pragma once
#include "Film.h"
#include "Repository.h"
#include <vector>
using std::vector;

//Clasa pentru functia de undo
class undo
{
	//vector<vector<Film>> undo_list;
public:
	//Functie ce va fi rescrisa de alte clase
	virtual void doUndo() = 0;
	//Destructor
	virtual ~undo() = default;
};

class UndoAdauga :public undo {
	//Clasa ce se ocupa cu undo ul la adaugare
	//Ultimul film ce a fost adaugat
	Film adaugaFilm;
	//repo pentru a apela functii
	Repository& repo;
	//lista in care se vor afla toate filmle sterse 
	vector<Film> addList;
public:
	UndoAdauga(Repository& repo) :repo{ repo } {};
	//functie ce face undo ul 
	void doUndo() override {
		repo.delete_film(adaugaFilm.getTitlu());
		addList.erase(addList.end() - 1);
	}
	//functie ce adauga in lista
	void add_to_undo(Film f) {
		addList.push_back(f);
		adaugaFilm = f;
	}

};

class UndoSterge : public undo {
	//Functie ce se ocupa de undo ul la stergere
	Film stergeFilm;
	Repository& repo;
	//lista unde se tin toate filmele nou adaugate
	vector<Film> deleteList;
public:
	UndoSterge(Repository& repo) :repo{ repo } {};
	void doUndo() override {
		repo.addFilm(stergeFilm);
		deleteList.erase(deleteList.end() - 1);
	}
	void add_to_del(Film f) {
		deleteList.push_back(f);
		stergeFilm = f;
	}
};

class UndoModifica : public undo {
	//Clasa pentru undo la modifiacari
	Repository& repo;
	typedef struct {
		string titlu;
		string gen;
		int an;
		string actor;
	}mod;
	//lista unde se tine titlul si anul inainte de modificari
	vector<mod> modList;
public:
	UndoModifica(Repository& repo) :repo{ repo } {};
	void doUndo() override {
		vector<mod>::iterator f;
		f = modList.end() - 1;
		repo.modify_film((*f).titlu, (*f).gen, (*f).an,(*f).actor);
		modList.erase(modList.end() - 1);
	}
	void add_to_mod(string new_tiltu, string titlu, int new_an,string new_actor) {
		modList.push_back({ titlu, new_tiltu, new_an ,new_actor});

	}
};