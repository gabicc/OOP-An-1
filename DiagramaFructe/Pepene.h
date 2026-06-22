//
// Created by gabi on 6/21/26.
//

#ifndef DIAGRAMAFRUCTE_PEPENE_H
#define DIAGRAMAFRUCTE_PEPENE_H

#include <iostream>
#include <vector>
#include "Fruct.h"

using namespace std;

class Pepene: public Fruct {
private:
    float kg;
public:
    Pepene(float kilos): kg{kilos} {};
    virtual ~Pepene() {

    };
    virtual void tipareste() override {
        cout << kg << " pepene ";
    }
};


#endif //DIAGRAMAFRUCTE_PEPENE_H
