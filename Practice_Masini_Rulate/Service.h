//
// Created by gabi on 5/14/26.
//

#ifndef PRACTICE_MASINI_RULATE_SERVICE_H
#define PRACTICE_MASINI_RULATE_SERVICE_H

#include "Repo.h"
#include "Validator.h"
#include "Masina.h"
#include <iostream>
#include <vector>

using namespace std;

class Service {
private:
    Repo repo;
    Validator val;
public:
    Service(Repo repo, Validator val): repo{repo}, val{val} {};
    void addMasina_srv(Masina m);
    void removeMasina_srv(char* nrMatricol);
    void updateMasina_srv(char* nrMatricol, Masina m);
    vector<Masina> get_all_srv();
};


#endif //PRACTICE_MASINI_RULATE_SERVICE_H
