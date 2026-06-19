//
// Created by gabi on 6/18/26.
//

#ifndef SMOOTHY_CLASE_SMOOTHY_H
#define SMOOTHY_CLASE_SMOOTHY_H

#include <string.h>
#include <iostream>
#include <assert.h>

using namespace std;

class Smoothy {
private:
    int pret;
public:
    Smoothy(int price): pret{price} {};
    int getPret() {
        return this->pret;
    }
    virtual string descriere() {

    }
};


#endif //SMOOTHY_CLASE_SMOOTHY_H
