//
// Created by gabi on 5/14/26.
//

#include "Service.h"
#include <string.h>

void Service::addMasina_srv(Masina m) {
    val.validateMasina(m);
    repo.addMasina(m);
}

void Service::removeMasina_srv(char *nrMatricol) {
    repo.removeMasina(nrMatricol);
}

void Service::updateMasina_srv(char *nrMatricol, Masina m) {
    val.validateMasina(m);
    repo.updateMasina(nrMatricol, m);
}

void Service::rentMasina_srv(char* nrMatricol) {
    Masina m = repo.find_by_nrMatricol(nrMatricol);
    if (m.getNrMatricol().empty()) {
        throw RepoException("Masina nu exista");
    }
    repo.removeMasina(nrMatricol);
}

vector<Masina> Service::get_all_srv() {
    return repo.get_all_repo();
}

vector<Masina> Service::sortareModel_srv() {
    vector<Masina> masini = repo.get_all_repo();
    for (int i = 0; i < masini.size() - 1; i++) {
        for (int j = i + 1; j < masini.size(); j++) {
            if (masini[i].getModel() > masini[j].getModel()) {
                Masina aux = masini[i];
                masini[i] = masini[j];
                masini[j] = aux;
            }
        }
    }
    return masini;
}
vector<Masina> Service::sortareNrMatricol_srv() {
    vector<Masina> masini = repo.get_all_repo();
    for (int i = 0; i < masini.size() - 1; i++) {
        for (int j = i + 1; j < masini.size(); j++) {
            if (masini[i].getNrMatricol() > masini[j].getNrMatricol()) {
                Masina aux = masini[i];
                masini[i] = masini[j];
                masini[j] = aux;
            }
        }
    }
    return masini;
}
