//
// Created by gabi on 6/20/26.
//

#ifndef DIAGRAMAPIZZA_PIZZACUPEPERONI_H
#define DIAGRAMAPIZZA_PIZZACUPEPERONI_H

#include "Pizza.h"

class PizzaCuPeperoni: public Pizza {
private:
    Pizza* p;
public:
    PizzaCuPeperoni(Pizza* pizza): Pizza{0}, p{pizza} {};
    virtual ~PizzaCuPeperoni() {
        delete p;
    }
    virtual string descriere() override {
        return p->descriere() + " cu peperoni";
    }
    virtual int getPret() override {
        return p->getPret() + 2;
    }
};


#endif //DIAGRAMAPIZZA_PIZZACUPEPERONI_H
