//
// Created by gabi on 6/20/26.
//

#ifndef DIAGRAMAUML_1_ANGAJAT_H
#define DIAGRAMAUML_1_ANGAJAT_H

#include "Participant.h"
#include <iostream>

using namespace std;

class Angajat: public Participant {
private:
    Participant* p;
public:
    Angajat(Participant* part): p{part} {};
    virtual ~Angajat() {
        delete p;
    };
    virtual void tipareste() override {
        //Participant::tipareste();
        p->tipareste();
        cout << " - angajat";
    }
    virtual bool eVoluntar() override {
        return false;
    }
};


#endif //DIAGRAMAUML_1_ANGAJAT_H
