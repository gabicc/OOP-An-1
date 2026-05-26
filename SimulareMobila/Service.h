//
// Created by gabi on 5/19/26.
//

#ifndef SIMULAREMOBILA_SERVICE_H
#define SIMULAREMOBILA_SERVICE_H

#include "Repo.h"
#include "Validator.h"
#include "Mobila.h"
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

class Service {
private:
    Repo repo;
    Validator val;
public:
    Service(Repo repo, Validator val): repo{repo}, val{val} {

    };
    ~Service() {

    }
    void addMobila_srv(Mobila m);
    vector<Mobila> filtrareType_srv(string type);
    vector<Mobila> sortareNrPieces_srv();
    vector<Mobila> sortareAssemblyTime_srv();
    vector<Mobila> getAll_srv() {
        return repo.getAll_repo();
    }
};


#endif //SIMULAREMOBILA_SERVICE_H
