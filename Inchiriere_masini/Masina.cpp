//
// Created by gabi on 3/30/26.
//

#include "Masina.h"
#include <iostream>

Masina::Masina(const string& nrInmatric, const string& produc, const string& mod, const string& t) {
    this->nrInmatriculare = nrInmatric;
    this->producator  = produc;
    this->model = mod;
    this->tip = t;
}

Masina::Masina(const Masina &other) {
    this->nrInmatriculare = other.nrInmatriculare;
    this -> producator = other.producator;
    this->model = other.model;
    this->tip = other.tip;
}

Masina::~Masina() {

}

void Masina::change_nrInmatriculare(const string& nrInmatriculare) {
    this->nrInmatriculare = nrInmatriculare;
}
const string& Masina::get_nr_inmatriculare() const{
    return this->nrInmatriculare;
}

void Masina::afis() {
    cout << "Masina[ nrInmatriculare: " << nrInmatriculare << ", producator: " << producator
    << ", model: " << model << ", tip: " << tip << "]\n";

}

Masina& Masina::operator=(const Masina& other) {
    this->nrInmatriculare = other.nrInmatriculare;
    this -> producator = other.producator;
    this->model = other.model;
    this->tip = other.tip;
    return *this;
}

Masina& Masina::operator=(const char* other) {
    this->nrInmatriculare = other;
    return *this;
}

bool Masina::operator==(const Masina& other) {
    return this->get_nr_inmatriculare() == other.nrInmatriculare;
}