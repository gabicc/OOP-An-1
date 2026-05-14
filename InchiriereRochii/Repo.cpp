//
// Created by gabi on 5/12/26.
//

#include "Repo.h"

Repo::Repo() {
    this->size = 0;
    this->capacity = 2;
    this->rochii = new Rochie[capacity];
}

Repo::~Repo() {

}

void Repo::resize() {
    this->capacity *= 2;
    //vector<Rochie> new_rochii(capacity, Rochie(0, "", 0, 0, false));
    Rochie* new_rochii = new Rochie[capacity];
    for (int i = 0; i < this->size; i++) {
        new_rochii[i] = this->rochii[i];
    }
    this->rochii = new_rochii;
}

void Repo::addRochie(Rochie r) {
    if (this->size == this->capacity) {
        resize();
    }
    int gasit = 0;
    for (int i = 0; i < this->size; i++) {
        if (rochii[i].get_cod() == r.get_cod())
            gasit = 1;
    }
    if (gasit == 1) {
        cout << "Rochia exista deja\n";
        return;
    }
    this->rochii[this->size] = r;
    this->size++;
}

void Repo::removeRochie(int cod) {
    int poz = -1;
    for (int i = 0; i < this->size; i++) {
        if (rochii[i].get_cod() == cod) {
            poz = i;
        }
    }
    if (poz == -1) {
        cout << "Rochia nu exista\n";
        return;
    }
    else {
        for (int i = poz; i < this->size - 1; i++) {
            rochii[i] = rochii[i + 1];
        }
        this->size--;
    }
}

void Repo::updateRochie(int cod, Rochie r_nou) {
    for (int i = 0; i < this->size; i++) {
        if (rochii[i].get_cod() == cod) {
            rochii[i] = r_nou;
            return;
        }
    }
}

void Repo::afisRochii() {
    for (int i = 0; i < this->size; i++) {
        cout << "Rochie[ cod: " << rochii[i].get_cod() << ", denumire: " << rochii[i].get_denumire() << ", marime: " << rochii[i].get_marime() << ", pret: " << rochii[i].get_pret() << ", disponibil: " << rochii[i].get_disponibil() << "]\n";
    }
}
