//
// Created by gabi on 6/20/26.
//

#ifndef DIAGRAMAUML_1_ONG_H
#define DIAGRAMAUML_1_ONG_H

#include "Participant.h"
#include <iostream>
#include <vector>

using namespace std;

class ONG {
private:
    vector<Participant*> participanti;
public:
    void add(Participant* p) {
        participanti.push_back(p);
    }
    vector<Participant*> getAll(bool voluntari) {
        vector<Participant*> rez;
        for (Participant* p: participanti) {
            if (p->eVoluntar() == voluntari)
                rez.push_back(p);
        }
        return rez;
    }
    static void distrugeONG(ONG& ong) {
        for (Participant* p: ong.participanti)
            delete p;
    }
};


#endif //DIAGRAMAUML_1_ONG_H
