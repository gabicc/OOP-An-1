//
// Created by gabi on 5/14/26.
//

#include "Service.h"

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

vector<Masina> Service::get_all_srv() {
    return repo.get_all_repo();
}
