//
// Created by gabi on 6/21/26.
//

#ifndef DIAGRAMAMANCARE_CUSOS_H
#define DIAGRAMAMANCARE_CUSOS_H

#include "Mancare.h"

class CuSos: public Mancare {
private:
    Mancare* m;
public:
    CuSos(Mancare* m1): Mancare{0}, m{m1} {};
    virtual ~CuSos() {
        delete m;
    }
    virtual string descriere() override {
        return m->descriere() + "cu sos";
    }
    virtual int getPret() override {
        return m->getPret() + 2;
    }
};


#endif //DIAGRAMAMANCARE_CUSOS_H
