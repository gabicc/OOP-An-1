//
// Created by gabi on 6/21/26.
//

#ifndef DIAGRAMAFRUCTE_PEPENEROSU_H
#define DIAGRAMAFRUCTE_PEPENEROSU_H

#include <iostream>
#include "Pepene.h"

using namespace std;

class PepeneRosu: public Pepene {
public:
    PepeneRosu(float kilograme): Pepene{kilograme} {};
    virtual ~PepeneRosu() {

    }
    virtual void tipareste() override {
        Pepene::tipareste();
        cout << " rosu";
    }
};


#endif //DIAGRAMAFRUCTE_PEPENEROSU_H
