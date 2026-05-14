//
// Created by gabi on 5/14/26.
//

#include "Repo.h"

void Repo::addMasina(Masina m) {
    for (const auto& masina: masini) {
        if (masina.getNrMatricol() == m.getNrMatricol()) {
            throw RepoException("Masina exista deja");
        }
    }
    masini.push_back(m);
}

void Repo::removeMasina(char *nrMatricol) {
    auto it = find_if(masini.begin(), masini.end(), [nrMatricol](const Masina& m) {
        return m.getNrMatricol() == nrMatricol;
    });
    if (it == masini.end()) {
        throw RepoException("Masina nu exista");
    }
    masini.erase(it);
}

void Repo::updateMasina(char *nrMatricol, Masina m) {
    auto it = find_if(masini.begin(), masini.end(), [nrMatricol](const Masina& current) {
       return current.getNrMatricol() == nrMatricol;
    });
    if (it == masini.end()) {
        throw RepoException("Masina nu exista");
    }
    *it = m;
}
