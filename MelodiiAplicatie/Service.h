//
// Created by gabi on 6/18/26.
//

#ifndef MELODIIAPLICATIE_SERVICE_H
#define MELODIIAPLICATIE_SERVICE_H

#include <iostream>
#include <string.h>
#include <vector>

#include "Melodie.h"
#include "Repo.h"
#include "Validator.h"

class Service {
private:
    Repo repo;
    Validator val;
public:
    Service(Repo repo, Validator val): repo{repo}, val{val} {};
    // returneaza vectorul sortat de melodii dupa rank
    vector<Melodie> get_all_srv() {
        return repo.get_all_repo();
    }
    // modifica melodia dupa id si ii poate modifica titlul si rankul
    void modifyMelodie_srv(int id, string titlu, string artist, int rank) {
        Melodie m(id, titlu, artist, rank);
        val.validateMelodie(m);
        repo.modifyMelodie(m);
    }
    // sterge melodie din vectorul de melodii dupa id
    void removeMelodie_srv(int id) {
        repo.removeMelodie(id);
    }
    void saveToFile_srv() {
        repo.saveToFile();
    }
};


#endif //MELODIIAPLICATIE_SERVICE_H
