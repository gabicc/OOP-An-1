//
// Created by gabi on 5/12/26.
//

#ifndef INCHIRIEREROCHII_SERVICE_H
#define INCHIRIEREROCHII_SERVICE_H

#include "Repo.h"
#include "Validator.h"
#include "Rochie.h"

class Service {
private:
    Repo repo;
    Validator validator;
public:
    Service(Repo repo, Validator val);
    ~Service();
    void addRochie_srv(Rochie r);
    void removeRochie_srv(int cod);
    void updateRochie_srv(int cod, Rochie r_nou);
    void afisRochii_srv();
    vector<Rochie> get_all_srv() {
        return repo.get_all_repo();
    }
};


#endif //INCHIRIEREROCHII_SERVICE_H
