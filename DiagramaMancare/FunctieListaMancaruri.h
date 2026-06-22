//
// Created by gabi on 6/21/26.
//

#ifndef DIAGRAMAMANCARE_FUNCTIELISTAMANCARURI_H
#define DIAGRAMAMANCARE_FUNCTIELISTAMANCARURI_H

#include "Mancare.h"
#include "Burger.h"
#include "CuCartofi.h"
#include "CuSos.h"
#include <vector>

vector<Mancare*> creeazaListaMancare() {
    vector<Mancare*> rez;
    Mancare* bigMac = new Burger("BigMac", 10);
    Mancare* bigMacCuCartofiSiSos = new CuSos(new CuCartofi(new Burger("BigMac", 10)));
    Mancare* zingerCartofi = new CuCartofi(new Burger("Zinger", 15));
    Mancare* zingerSos = new CuSos(new Burger("Zinger", 15));
    rez.push_back(bigMac);
    rez.push_back(bigMacCuCartofiSiSos);
    rez.push_back(zingerCartofi);
    rez.push_back(zingerSos);
    return rez;
}

#endif //DIAGRAMAMANCARE_FUNCTIELISTAMANCARURI_H
