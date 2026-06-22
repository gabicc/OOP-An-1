//
// Created by gabi on 6/20/26.
//

#ifndef DIAGRAMAPIZZA_BASICPIZZA_H
#define DIAGRAMAPIZZA_BASICPIZZA_H

#include "Pizza.h"

class BasicPizza: public Pizza {
private:
    string denumire;
public:
    BasicPizza(string denumire, int pret): Pizza{pret}, denumire{denumire} {};
    virtual ~BasicPizza() {

    }
    virtual string descriere() override {
        return denumire;
    }
};


#endif //DIAGRAMAPIZZA_BASICPIZZA_H
