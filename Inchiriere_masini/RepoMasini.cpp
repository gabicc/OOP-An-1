//
// Created by gabi on 3/30/26.
//

#include "RepoMasini.h"

#include <iostream>
#include <ostream>

RepoMasini::RepoMasini() {
}

RepoMasini::~RepoMasini() {
}

void RepoMasini::adaugaMasina(const Masina &m) {
}

void RepoMasini::stergeMasina(const string &nrInmatric) {
}

void RepoMasini::modificaMasina(const string &nrInamtriculare_vechi, const string &nrInamtriculare_nou) {
}

void RepoMasini::afis_Masini() {
    for (auto &m: masini) {
        m.afis();
    }
}
