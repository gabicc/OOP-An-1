#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>

using namespace std;


MD::MD() {
}


void MD::adauga(TCheie c, TValoare v) {
	IteratorLDI<std::pair<TCheie, LDI<TValoare>*>> it = multidict.iterator();
	it.prim();
	while (it.valid()) {
		//fiecare element returnat de iterator trebuie sa fie in multime
		std::pair<TCheie, LDI<TValoare>*> e = it.element();
		if (e.first == c) {
			e.second->adauga(v);
			return;
		}
		it.urmator();
	}
	LDI<TValoare>* valori = new LDI<TValoare>();
	valori->adauga(v);
	std::pair<TCheie, LDI<TValoare>*> pereche(c, valori);
	multidict.adauga(pereche);
}


bool MD::sterge(TCheie c, TValoare v) {
	IteratorLDI<std::pair<TCheie, LDI<TValoare>*>> it = multidict.iterator();
	it.prim();
	while (it.valid()) {
		//fiecare element returnat de iterator trebuie sa fie in multime
		std::pair<TCheie, LDI<TValoare>*> e = it.element();
		if (e.first == c) {
			//e.second.adauga(v);
			bool b = e.second->sterge(v);
			if (b == true) {
				if (e.second->vida() == true) {
					multidict.sterge(e);
				}
			}
			return b;
		}
		it.urmator();
	}
	return false;
}


vector<TValoare> MD::cauta(TCheie c) const {
	IteratorLDI<std::pair<TCheie, LDI<TValoare>*>> it = multidict.iterator();
	it.prim();
	while (it.valid()) {
		//fiecare element returnat de iterator trebuie sa fie in multime
		std::pair<TCheie, LDI<TValoare>*> e = it.element();
		if (e.first == c) {
			vector<TValoare> valori;
			IteratorLDI<TValoare> it_valori = e.second->iterator();
			it_valori.prim();
			while(it_valori.valid()) {
				TValoare val = it_valori.element();
				valori.push_back(val);
				it_valori.urmator();
			}
			return valori;
		}
		it.urmator();
	}
	return vector<TValoare>();
}


int MD::dim() const {
	IteratorLDI<std::pair<TCheie, LDI<TValoare>*>> it = multidict.iterator();
	it.prim();
	int cont = 0;
	while (it.valid()) {
		//fiecare element returnat de iterator trebuie sa fie in multime
		std::pair<TCheie, LDI<TValoare>*> e = it.element();
			IteratorLDI<TValoare> it_valori = e.second->iterator();
			it_valori.prim();
			while(it_valori.valid()) {
				cont++;
				it_valori.urmator();
			}
		it.urmator();
	}
	return cont;
}


bool MD::vid() const {
	return multidict.vida();
}

IteratorMD MD::iterator() const {
	return IteratorMD(*this);
}


MD::~MD() {
	/* de adaugat */
}

