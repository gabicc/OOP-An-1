//
// Created by gabi on 6/20/26.
//

#ifndef DIAGRAMAUML_1_DIRECTOR_H
#define DIAGRAMAUML_1_DIRECTOR_H

#include "Personal.h"
#include <iostream>

class Director: public Personal {
public:
    Director(string name): Personal{name} {};
    virtual void tipareste() override {
        Personal::tipareste();
        cout << "  Director";
    }
};


#endif //DIAGRAMAUML_1_DIRECTOR_H
