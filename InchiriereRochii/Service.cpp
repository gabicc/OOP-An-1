//
// Created by gabi on 5/12/26.
//

#include "Service.h"
#include <fstream>

using namespace std;

Service::Service(Repo repo, Validator val): repo{repo}, validator{val} {
}

Service::~Service() {

}

void Service::addRochie_srv(Rochie r) {
    validator.validare_rochie(r);
    this->repo.addRochie(r);
}

void Service::removeRochie_srv(int cod) {
    this->repo.removeRochie(cod);
}

void Service::updateRochie_srv(int cod, Rochie r_nou) {
    validator.validare_rochie(r_nou);
    this->repo.updateRochie(cod, r_nou);
}

void Service::afisRochii_srv() {
    this->repo.afisRochii();
}