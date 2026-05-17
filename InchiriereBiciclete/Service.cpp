//
// Created by gabi on 5/17/26.
//

#include "Service.h"

Service::~Service() {

}
void Service::inchiriereBicicleta_srv(int cod) {
    repo.inchiriereBicicleta(cod);
}
vector<Bicicleta> Service::sortareMarime_srv() {
    return repo.sortareMarime();
}
vector<Bicicleta> Service::sortarePret_srv() {
    return repo.sortarePret();
}
vector<Bicicleta> Service::nesortat_srv() {
    return repo.nesortat();
}
vector<Bicicleta> Service::get_all_srv() {
    return repo.get_all_repo();
}