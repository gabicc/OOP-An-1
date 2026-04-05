//
// Created by gabi on 3/30/26.
//

#include "RepoMasini.h"

#include <iostream>
#include <ostream>

#include "Validator.h"

RepoMasini::RepoMasini() {
}

RepoMasini::~RepoMasini() {
}

void RepoMasini::adaugaMasina(const Masina &m) {
    if (masini.find(m)) {
        throw ValidationException("Masina exista deja");
    }
    masini.add(m);
}

void RepoMasini::stergeMasina(const string &nrInmatric) {
    // for (auto& m: masini) {
    //     if (m.get_nrInmatriculare() == nrInmatric) {
    //         masini.pop_back();
    //     }
    // }
    const Masina m(nrInmatric, "", "", "");
    //const Masina& n = m;
    if (!masini.find(m)) {
        throw ValidationException("Masina stearsa nu exista");
    }
    masini.remove(m);
}

void RepoMasini::modificaMasina(const string &nrInamtriculare_vechi, const string &nrInamtriculare_nou) {
    // for (auto& m: masini) {
    //     if (m.get_nrInmatriculare() == nrInamtriculare_vechi)
    //         m.change_nrInmatriculare(nrInamtriculare_nou);
    // }
    const Masina m(nrInamtriculare_vechi, "", "", "");
    const Masina m_new(nrInamtriculare_nou, "", "", "");
    if (!masini.find(m)) {
        throw ValidationException("Masina modificata nu exista");
    }
    masini.change(m, m_new);
}

void RepoMasini::afis_Masini() {
    // for (auto &m: masini) {
    //     m.afis();
    // }
    Node<Masina>* curent = masini.getHead();
    while (curent != NULL) {
        curent->getVal().afis();
        curent = curent->getNext();
    }
}

vector<Masina> RepoMasini::get_all() const {
    vector<Masina> all;
    Node<Masina>* curent = masini.getHead();
    while (curent != NULL) {
        all.push_back(curent->getVal());
        curent = curent->getNext();
    }
    return all;
}


