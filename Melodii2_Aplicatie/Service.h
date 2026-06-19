//
// Created by gabi on 6/19/26.
//

#ifndef MELODII2_APLICATIE_SERVICE_H
#define MELODII2_APLICATIE_SERVICE_H

#include <iostream>
#include <string.h>
#include <vector>
#include "Melodie.h"
#include <fstream>
#include <sstream>
#include "Melodie.h"
#include "Validator.h"
#include "Repo.h"

class Service {
private:
    Repo repo;
    Validator val;
public:
    Service(Repo repo, Validator val): repo{repo}, val{val} {};
    vector<Melodie> get_all_srv() {
        // pre: -
        // post: returneaaza lista de melodii din repo
        return repo.get_all_repo();
    }
    void addMelodie_srv(string titlu, string artist, string gen);
    void removeMelodie_srv(int id);
};


#endif //MELODII2_APLICATIE_SERVICE_H
