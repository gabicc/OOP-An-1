//
// Created by gabi on 5/18/26.
//

#ifndef PROCESORSIPLACADEBAZA_SERVICE_H
#define PROCESORSIPLACADEBAZA_SERVICE_H

#include <iostream>
#include "Repo.h"
#include "Validator.h"
#include "Procesor.h"
#include "PlacaDeBaza.h"

class Service {
private:
    Repo repo;
    Validator val;
public:
    Service(Repo repo, Validator val): repo{repo}, val{val} {};
    ~Service() {

    }
    void addPlaca_srv(PlacaDeBaza& p) {
        val.validate_placa(p);
        repo.addPlaca(p);
    }
    vector<PlacaDeBaza> filtrarePlaciSoclu_srv(int soclu) {
        return repo.filtrarePlaciSoclu(soclu);
    }
    double pretTotal_srv(double pretProcesor, double pretPlaca) {
        return repo.pretTotal(pretProcesor, pretPlaca);
    }
    vector<Procesor> get_all_procesor_srv() {
        return this->repo.get_all_procesor_repo();
    }
    vector<PlacaDeBaza> get_all_placi_srv() {
        return this->repo.get_all_placi_repo();
    }
};


#endif //PROCESORSIPLACADEBAZA_SERVICE_H
