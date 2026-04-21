//
// Created by gabi on 3/30/26.
//

#include "RepoMasini.h"

#include <iostream>
#include <ostream>
#include <algorithm>

#include "Validator.h"

RepoMasini::RepoMasini() {
}

RepoMasini::~RepoMasini() {
}

void RepoMasini::adaugaMasina(const Masina &m) {
    auto it = find(masini.begin(), masini.end(), m);
    if (it != masini.end()) {
        throw ValidationException("Masina exista deja");
    }
    masini.push_back(m);
}

void RepoMasini::stergeMasina(const string &nrInmatric) {
    // for (auto& m: masini) {
    //     if (m.get_nrInmatriculare() == nrInmatric) {
    //         masini.pop_back();
    //     }
    // }
    const Masina m(nrInmatric, "", "", "");
    //const Masina& n = m;
    auto it = find(masini.begin(), masini.end(), m);
    if (it == masini.end())  {
        throw ValidationException("Masina stearsa nu exista");
    }
    masini.erase(it);
}

void RepoMasini::modificaMasina(const string &nrInamtriculare_vechi, const string &nrInamtriculare_nou) {
    // for (auto& m: masini) {
    //     if (m.get_nrInmatriculare() == nrInamtriculare_vechi)
    //         m.change_nrInmatriculare(nrInamtriculare_nou);
    // }
    const Masina m(nrInamtriculare_vechi, "", "", "");
    const Masina m_new(nrInamtriculare_nou, "", "", "");
    auto it = find(masini.begin(), masini.end(), m);
    if (it == masini.end()) {
        throw ValidationException("Masina modificata nu exista");
    }
    //masini.change(m, m_new);
    *it = m_new;
}

void RepoMasini::afis_Masini() {
    /*for (auto &m: masini) {
         m.afis();
    }*/
    for (vector<Masina>::iterator it = masini.begin(); it != masini.end(); ++it) {
        (*it).afis();
    }

    /*Node<Masina>* curent = masini.getHead();
    while (curent != NULL) {
        curent->getVal().afis();
        curent = curent->getNext();
    }
    */
}

vector<Masina> RepoMasini::get_all() const {
    /*vector<Masina> all;
    Node<Masina>* curent = masini.getHead();
    while (curent != NULL) {
        all.push_back(curent->getVal());
        curent = curent->getNext();
    }
    */
    return masini;
}

void RepoMasini::golire_repo() {
    masini.clear();
}


vector<Masina> RepoMasini::filtreaza_dupa_pruducator(const string& producator) const {
    auto filtreaza = [&](const string& valoare, auto getter) {
        vector<Masina> rezultat;
        for (const auto& m: masini) {
            if (getter(m) == valoare)
                rezultat.push_back(m);
        }
        return rezultat;
    };
    return filtreaza(producator, [](const Masina& m) {
        return m.get_producator();
    });
}
vector<Masina> RepoMasini::filtreaza_dupa_tip(const string& tip) const {
    auto filtreaza = [&](const string& valoare, auto getter) {
        vector<Masina> rezultat;
        for (const auto& m: masini) {
            if (getter(m) == valoare)
                rezultat.push_back(m);
        }
        return rezultat;
    };
    return filtreaza(tip, [](const Masina& m) {
        return m.get_tip();
    });
}