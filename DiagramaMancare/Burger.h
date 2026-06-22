//
// Created by gabi on 6/21/26.
//

#ifndef DIAGRAMAMANCARE_BURGER_H
#define DIAGRAMAMANCARE_BURGER_H

#include "Mancare.h"

class Burger: public Mancare {
private:
    string nume;
public:
    Burger(string name, int pret): Mancare{pret}, nume{name} {};
    virtual ~Burger() {

    }
    virtual string descriere() override {
        return nume;
    }
};


#endif //DIAGRAMAMANCARE_BURGER_H
