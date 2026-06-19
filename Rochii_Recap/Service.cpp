//
// Created by gabi on 6/13/26.
//

#include "Service.h"

void Service::addRochie_srv(Rochie r) {
    val.validateRochie(r);
    repo.addRochie(r);
}
void Service::removeRochie_srv(int cod) {
    repo.removeRochie(cod);
}
bool Service::findRochie_srv(int cod) {
    return repo.findRochie(cod);
}
void Service::updateRochie_srv(Rochie r_nou) {
    repo.updateRochie(r_nou);
}