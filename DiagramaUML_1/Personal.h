//
// Created by gabi on 6/20/26.
//

#ifndef DIAGRAMAUML_1_PERSONAL_H
#define DIAGRAMAUML_1_PERSONAL_H

#include "Participant.h"
#include <iostream>

using namespace std;

class Personal: public Participant {
private:
    string nume;
public:
    Personal(string name): nume{name} {};
    virtual ~Personal() {};
    virtual void tipareste() {
        cout << nume;
    }
};


#endif //DIAGRAMAUML_1_PERSONAL_H
