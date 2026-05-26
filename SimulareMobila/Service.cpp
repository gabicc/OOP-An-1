//
// Created by gabi on 5/19/26.
//

#include "Service.h"

void Service::addMobila_srv(Mobila m) {
    val.validateMobila(m);
    repo.addMobila(m);
}
vector<Mobila> Service::filtrareType_srv(string type) {
    return repo.filtrareType(type);
}

vector<Mobila> Service::sortareNrPieces_srv() {
    return repo.sortareNrPieces();
}
vector<Mobila> Service::sortareAssemblyTime_srv() {
    return repo.sortareAssemblyTime();
}
