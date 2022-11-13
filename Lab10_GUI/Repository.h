#pragma once
#include "Film.h"
#include <vector>
#include "validation.h"
#include <assert.h>
using std::vector;
//#include "vectorDinamic.h"

//Modul ce se ocupa cu gestiunea memoriei si cu legatura dintre aceasta si aplicatie
class RepoException {
	//clasa pentru gestionarea exceptilor ce pot aparea
private:
	//exceptile sub forma de string
	string errMsg;
public:
	RepoException(string errMsg) : errMsg{ errMsg } {};
	//functie ce returneaza totate erorile descoperite sub forma de string
	string getMsg() {
		return this->errMsg;
	}
};

class Repository
{
private:
	//vectorul in care tinem toate entitatile de tip film
	vector<Film> allFilme;

public:
	//constructori
	Repository() = default;
	Repository(const Repository& re) = delete;

	//functie pentru adaugarea unui nou film in memorie
	virtual void addFilm(const Film& new_film);

	//verifica daca un film exista sau nu deja in memorie
	//return true daca nu exista, false altfel
	bool exista(const Film& f);

	//functie ce verifica daca un film cu titlul dat se afla in memorie 
	//return filmul gasit daca exista
	//daca nu exista throw RepoException
	const Film& find(string titlu);

	//functie ce verifica daca un film cu titlul dat si cu genul dat se afla in memorie 
	//return filmul gasit daca exista
	//daca nu exista throw RepoException
	const Film& find2(string titlu, string gen);

	//functie ce returneaza toate filmele din memorie sub forma unui vector din stl
	const vector<Film>& getAll();

	//Functie ce sterge un film cu titlul dat din memorie
	virtual void delete_film(string titlu);

	//Functie ce modifica primul film cu titlul dat din memorie
	//ii inlocuieste titlul cu new_titlu si anul cu new_an
	void modify_film(string titlu, string new_tiltu, int new_an,string new_actor);

};
//teste
void repo_tests();

void repo_test_add();
void repo_test_find();
void repo_test_modify();
void repo_test_delete();
