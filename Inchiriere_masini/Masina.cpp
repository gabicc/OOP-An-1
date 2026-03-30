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
Masina::~Masina() {

}

void Masina::change_nrInmatriculare(const string& nrInmatriculare) {
    this->nrInmatriculare = nrInmatriculare;
}
const string& Masina::get_nrInmatriculare() {
    return this->nrInmatriculare;
}

void Masina::afis() {
    cout << "Masina: nrInmatriculare" << nrInmatriculare << ", producator: " << producator
    << ", model: " << model << ", tip: " << tip << '\n';

}