//
// Created by gabi on 5/12/26.
//

#include "Rochie.h"

Rochie::~Rochie() {

}

int Rochie::get_cod() {
    return this->cod;
}

const string Rochie::get_denumire() {
    return this->denumire;
}

double Rochie::get_marime() {
    return this->marime;
}

double Rochie::get_pret() {
    return this->pret;
}

bool Rochie::get_disponibil() {
    return this->disponibil;
}

void Rochie::operator=(const Rochie& other) {
    this->cod = other.cod;
    this->denumire = other.denumire;
    this->marime = other.marime;
    this->pret = other.pret;
    this->disponibil = other.disponibil;
}
