//
// Created by gabi on 6/21/26.
//

#ifndef DIAGRAMAFRUCTE_CUSAMBURE_H
#define DIAGRAMAFRUCTE_CUSAMBURE_H

#include <iostream>

using namespace std;

#include "Fruct.h"

class CuSambure: public Fruct {
private:
    Fruct* f;
public:
    CuSambure(Fruct* fruct): f{fruct} {};
    virtual ~CuSambure() {
        delete f;
    }
    virtual void tipareste() override {
        f->tipareste();
        cout << " cu samburi ";
    }
    virtual bool eCuSambure() override {
        return true;
    }
};


#endif //DIAGRAMAFRUCTE_CUSAMBURE_H
