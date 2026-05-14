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
    Service();
    ~Service();
    void addRochie_srv(Rochie r);
    void removeRochie_srv(int cod);
    void updateRochie_srv(int cod, Rochie r_nou);
    void afisRochii_srv();
    void load_from_file(string filename);
};


#endif //INCHIRIEREROCHII_SERVICE_H
