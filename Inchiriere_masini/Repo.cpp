//
// Created by gabi on 4/28/26.
//

#include "Repo.h"
#include <random>
#include "Validator.h"

void Repo::arunca_exceptie_random() const {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    if (dis(gen) < probabilitate_aruncare_exceptie) {
        throw ValidationException("Exceptie aruncata random");
    }
}

void Repo::addMasina(const string &nrInmatric, const string &producator, const string &model, const string &tip) {
    if (masini.find(nrInmatric) != masini.end()) {
        throw ValidationException("Masina exista deja");
    }
    masini.insert({nrInmatric, Masina(nrInmatric, producator, model, tip)});
}

void Repo::removeMasina(const string &nrInmatric) {
    auto it = masini.find(nrInmatric);
    if (it == masini.end()) {
        throw ValidationException("Masina de sters nu exista");
    }
    masini.erase(it);
}

void Repo::modifyMasina(const string &nrInmatric_vechi, const string &nrInmatric_nou) {
    auto it = masini.find(nrInmatric_vechi);
    if (it == masini.end()) {
        throw ValidationException("Masina de modificat nu exista");
    }
    if (masini.find(nrInmatric_nou) != masini.end()) {
        throw ValidationException("Masina cu numar nou exista deja");
    }
    Masina masina_modificata = it->second;
    masini.erase(it);
    masina_modificata.change_nrInmatriculare(nrInmatric_nou);
    masini.insert({nrInmatric_nou, masina_modificata});
}
