//
// Created by gabi on 6/20/26.
//

#ifndef DIAGRAMAUML_1_FUNCTIEONG_H
#define DIAGRAMAUML_1_FUNCTIEONG_H

#include "ONG.h"
#include "Participant.h"
#include "Administrator.h"
#include "Angajat.h"
#include "Director.h"
#include "Personal.h"

ONG creeazaONG() {
    ONG ong;
    Participant* p1 = new Administrator("CalinV");
    ong.add(p1);
    Participant* p2 = new Angajat(new Administrator("IlieA"));
    ong.add(p2);
    Participant* p3 = new Director("ValerV");
    ong.add(p3);
    Participant* p4 = new Director("ValeriuA");
    p4 = new Angajat(p4);
    ong.add(p4);
    Participant* p5 = new Personal("VasileV");
    ong.add(p5);
    return ong;
}

#endif //DIAGRAMAUML_1_FUNCTIEONG_H
