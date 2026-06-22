//
// Created by gabi on 6/20/26.
//

#ifndef PRODUSEAPLICATIE_PRODUS_H
#define PRODUSEAPLICATIE_PRODUS_H

#include <iostream>
#include <string.h>

using namespace std;

class Produs {
private:
    int id;
    string nume;
    string tip;
    double pret;
    // fiecare produs are id, nume, tip si pret
public:
    Produs(int id, string nume, string tip, double pret): id{id}, nume{nume}, tip{tip}, pret{pret} {};
    int getId() {
        return id;
    }
    string getNume() {
        return nume;
    }
    string getTip() {
        return tip;
    }
    double getPret() {
        return pret;
    }
    void operator=(Produs& other) {
        // pre: other - Produs
        // post: facem operatia de egalitate in care un prouds primeste valoarea altuia
        id = other.id;
        nume = other.nume;
        tip = other.tip;
        pret = other.pret;
    }
};


#endif //PRODUSEAPLICATIE_PRODUS_H
