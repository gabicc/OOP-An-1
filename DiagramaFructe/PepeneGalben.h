//
// Created by gabi on 6/21/26.
//

#ifndef DIAGRAMAFRUCTE_PEPENEGALBEN_H
#define DIAGRAMAFRUCTE_PEPENEGALBEN_H

#include <iostream>
#include "Pepene.h"

using namespace std;

class PepeneGalben: public Pepene {
public:
    PepeneGalben(float kgs): Pepene{kgs} {};
    virtual ~PepeneGalben() {

    };
    virtual void tipareste() override {
        Pepene::tipareste();
        cout << " galben ";
    }
};


#endif //DIAGRAMAFRUCTE_PEPENEGALBEN_H
