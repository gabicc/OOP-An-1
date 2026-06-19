//
// Created by gabi on 6/13/26.
//

#ifndef ROCHII_RECAP_SERVICE_H
#define ROCHII_RECAP_SERVICE_H
#include "Repo.h"
#include "Validator.h"
#include "Rochie.h"

class Service {
private:
    Repo& repo;
    Validator& val;
public:
    Service(Repo& repo, Validator& val): repo{repo}, val{val} {};
    virtual ~Service() {};
    void addRochie_srv(Rochie r);
    void removeRochie_srv(int cod);
    bool findRochie_srv(int cod);
    void updateRochie_srv(Rochie r_nou);
    vector<Rochie> get_all_srv() {
        return repo.get_all_rochii_repo();
    }
};


#endif //ROCHII_RECAP_SERVICE_H
