//
// Created by gabi on 6/20/26.
//

#ifndef DIAGRAMAPIZZA_PIZZACUCIUPERCI_H
#define DIAGRAMAPIZZA_PIZZACUCIUPERCI_H

#include "Pizza.h"

class PizzaCuCiuperci: public Pizza {
private:
    Pizza* p;
public:
    PizzaCuCiuperci(Pizza* pizza): Pizza{0}, p{pizza} {};
    virtual ~PizzaCuCiuperci() {
        delete p;
    };
    virtual string descriere() override {
        return p->descriere() + " cu ciuperci";
    }
    virtual int getPret() override {
        return p->getPret() + 3;
    }
};


#endif //DIAGRAMAPIZZA_PIZZACUCIUPERCI_H
