//
// Created by gabi on 3/30/26.
//

#include "Masina.h"
#include <iostream>
#include <random>

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

void Masina::afis() const {
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

bool Masina::operator==(const Masina& other) const {
    return this->get_nr_inmatriculare() == other.nrInmatriculare;
}

char random_letter(mt19937& mt) {
    static uniform_int_distribution<int> distLetter(0, 25);
    return static_cast<char>('A' + distLetter(mt));
}

Masina Masina::genereaza_masina(int index) {
    mt19937 mt{ random_device{}()};
    uniform_int_distribution<> dist(1, 100);
    int rndNr = dist(mt);
    char a = random_letter(mt), b = random_letter(mt), c = random_letter(mt), d = random_letter(mt), e = random_letter(mt);
    string result;
    result += a;
    result += b;
    result += to_string(rndNr);
    result += c;
    result += d;
    result += e;
    string producator;
    for (int i = 0; i < 5; i++) {
        char a = random_letter(mt);
        producator += a;
    }
    string model;
    for (int i = 0; i < 5; i++) {
        char a = random_letter(mt);
        model += a;
    }
    string tip;
    for (int i = 0; i < 5; i++) {
        char a = random_letter(mt);
        tip += a;
    }
    return Masina(result, producator, model, tip);
}