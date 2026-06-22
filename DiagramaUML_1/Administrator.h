//
// Created by gabi on 6/20/26.
//

#ifndef DIAGRAMAUML_1_ADMINISTRATOR_H
#define DIAGRAMAUML_1_ADMINISTRATOR_H

#include "Personal.h"

class Administrator: public Personal {
public:
    Administrator(string nume): Personal{nume} {};
    virtual void tipareste() {
        Personal::tipareste();
        cout << "  Administrator";
    }
};


#endif //DIAGRAMAUML_1_ADMINISTRATOR_H
