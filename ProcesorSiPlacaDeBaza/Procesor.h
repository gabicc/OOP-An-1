//
// Created by gabi on 5/18/26.
//

#ifndef PROCESORSIPLACADEBAZA_PROCESOR_H
#define PROCESORSIPLACADEBAZA_PROCESOR_H

#include <string.h>
#include <iostream>

using namespace std;

class Procesor {
private:
    string nume;
    int nrThreads;
    int soclu;
    double pret;
public:
    Procesor(string nume, int nrThreads, int soclu, double pret): nume{nume}, nrThreads{nrThreads}, soclu{soclu}, pret{pret} {};
    virtual ~Procesor() {

    }
    string getNume() const {
        return this->nume;
    }
    int getNrThrd() const {
        return this->nrThreads;
    }
    int getSoclu() const {
        return this->soclu;
    }
    double getPret() const {
        return this->pret;
    }
    void operator=(const Procesor& other) {
        this->nume = other.nume;
        this->nrThreads = other.nrThreads;
        this->soclu = other.soclu;
        this->pret = other.pret;
    }
};

#endif //PROCESORSIPLACADEBAZA_PROCESOR_H
