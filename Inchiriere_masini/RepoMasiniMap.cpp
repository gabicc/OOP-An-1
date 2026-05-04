//
// Created by gabi on 3/30/26.
//

#include "RepoMasiniMap.h"

#include <iostream>
#include <ostream>
#include <algorithm>

#include "UndoAdauga.h"
#include "UndoModifica.h"
#include "UndoSterge.h"
#include "Validator.h"
#include <random>

RepoMasiniMap::RepoMasiniMap(double probabilitate_aruncare_exceptie): probabilitate_aruncare_exception(probabilitate_aruncare_exceptie) {
}

RepoMasiniMap::~RepoMasiniMap() {
    //TODO delete actiuni_undo
}

void RepoMasiniMap::adaugaMasina(const Masina &m) {
    arunca_exceptie_random();
    auto it = masini.find(m.get_nr_inmatriculare());
    if (it != masini.end()) {
        throw ValidationException("Masina exista deja");
    }
    masini.insert({m.get_nr_inmatriculare(), m});
    actiuni_undo.push_back(new UndoAdauga(this->get_all()));
}

void RepoMasiniMap::stergeMasina(const string &nrInmatric) {
    // for (auto& m: masini) {
    //     if (m.get_nrInmatriculare() == nrInmatric) {
    //         masini.pop_back();
    //     }
    // }
    arunca_exceptie_random();
    const Masina m(nrInmatric, "", "", "");
    //const Masina& n = m;
    auto it = masini.find(m.get_nr_inmatriculare());
    if (it == masini.end())  {
        throw ValidationException("Masina stearsa nu exista");
    }
    Masina masina_stearsa = it->second;
    masini.erase(it);
    actiuni_undo.push_back(new UndoSterge(this->get_all(), masina_stearsa));
}

void RepoMasiniMap::modificaMasina(const string &nrInamtriculare_vechi, const string &nrInamtriculare_nou) {
    // for (auto& m: masini) {
    //     if (m.get_nrInmatriculare() == nrInamtriculare_vechi)
    //         m.change_nrInmatriculare(nrInamtriculare_nou);
    // }
    arunca_exceptie_random();
    const Masina m(nrInamtriculare_vechi, "", "", "");
    const Masina m_new(nrInamtriculare_nou, "", "", "");
    auto it = masini.find(m.get_nr_inmatriculare());
    if (it == masini.end()) {
        throw ValidationException("Masina modificata nu exista");
    }
    //masini.change(m, m_new);
    it->second = m_new;
    actiuni_undo.push_back(new UndoModifica(this->get_all(), m, nrInamtriculare_nou));
}

void RepoMasiniMap::afis_Masini() {
    /*for (auto &m: masini) {
         m.afis();
    }*/
    arunca_exceptie_random();
    for (auto it = masini.begin(); it != masini.end(); ++it) {
        (it->second).afis();
    }

    /*Node<Masina>* curent = masini.getHead();
    while (curent != NULL) {
        curent->getVal().afis();
        curent = curent->getNext();
    }
    */
}

vector<Masina> RepoMasiniMap::get_all() const {
    /*vector<Masina> all;
    Node<Masina>* curent = masini.getHead();
    while (curent != NULL) {
        all.push_back(curent->getVal());
        curent = curent->getNext();
    }
    */
    arunca_exceptie_random();
    vector<Masina> all_masini;
    for (auto it = masini.begin(); it != masini.end(); it++) {
        all_masini.push_back(it->second);
    }
    return all_masini;
}

void RepoMasiniMap::golire_repo() {
    arunca_exceptie_random();
    masini.clear();
}


vector<Masina> RepoMasiniMap::filtreaza_dupa_pruducator(const string& producator) const {
    arunca_exceptie_random();
    vector<Masina> rezultat;
    for (auto it = masini.begin(); it != masini.end(); it++) {
        if (it->second.get_producator() == producator)
            rezultat.push_back(it->second);
    }
    return rezultat;
}
vector<Masina> RepoMasiniMap::filtreaza_dupa_tip(const string& tip) const {
    arunca_exceptie_random();
    vector<Masina> rezultat;
    for (auto it = masini.begin(); it != masini.end(); it++) {
        if (it->second.get_tip() == tip)
            rezultat.push_back(it->second);
    }
    return rezultat;
}

void RepoMasiniMap::Undo() {
    arunca_exceptie_random();
    if (!actiuni_undo.empty()) {
        ActiuneUndo* ultima_actiune = actiuni_undo.back();
        vector<Masina> masini_vector = ultima_actiune->doUndo();
        masini.clear();
        for (const auto& m: masini_vector) {
            masini.insert({m.get_nr_inmatriculare(), m});
        }
        actiuni_undo.pop_back();
        delete ultima_actiune;

    }
}

void RepoMasiniMap::arunca_exceptie_random() const {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    if (dis(gen) < probabilitate_aruncare_exception) {
        //throw ValidationException("Exceptie aruncata random");
    }
}

