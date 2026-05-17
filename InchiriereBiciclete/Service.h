//
// Created by gabi on 5/17/26.
//

#ifndef INCHIRIEREBICICLETE_SERVICE_H
#define INCHIRIEREBICICLETE_SERVICE_H

#include "Repo.h"
#include "Validator.h"
#include "Bicicleta.h"

class Service {
private:
    Repo repo;
    Validator val;
public:
    Service(Repo repo, Validator val): repo{repo}, val{val} {};
    virtual ~Service();
    void inchiriereBicicleta_srv(int cod);
    vector<Bicicleta> sortareMarime_srv();
    vector<Bicicleta> sortarePret_srv();
    vector<Bicicleta> nesortat_srv();
    vector<Bicicleta> get_all_srv();
};


#endif //INCHIRIEREBICICLETE_SERVICE_H
