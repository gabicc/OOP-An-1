//
// Created by gabi on 5/18/26.
//

#ifndef PROCESORSIPLACADEBAZA_PLACADEBAZA_H
#define PROCESORSIPLACADEBAZA_PLACADEBAZA_H

#include <string.h>
#include <iostream>

using namespace std;

class PlacaDeBaza {
private:
    string nume;
    int soclu;
    double pret;
public:
    PlacaDeBaza(string nume, int soclu, double pret): nume{nume}, soclu{soclu}, pret{pret} {};
    virtual ~PlacaDeBaza() {

    }
    string getNumePlaca() const {
        return this->nume;
    }
    int getSocluPlaca() const {
        return this->soclu;
    }
    double getPretPlaca() const {
        return this->pret;
    }
    void operator=(const PlacaDeBaza& other) {
        this->nume = other.nume;
        this->soclu = other.soclu;
        this->pret = other.pret;
    }
};

#endif //PROCESORSIPLACADEBAZA_PLACADEBAZA_H
