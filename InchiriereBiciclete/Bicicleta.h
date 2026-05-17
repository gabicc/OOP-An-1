//
// Created by gabi on 5/17/26.
//

#ifndef INCHIRIEREBICICLETE_BICICLETA_H
#define INCHIRIEREBICICLETE_BICICLETA_H

#include <string.h>
#include <iostream>

using namespace std;

class Bicicleta {
private:
    int cod;
    string denumire;
    string marime;
    double pret;
    bool disponibila;
public:
    Bicicleta(int cod, string denumire, string marime, double pret, bool disponibila):
    cod{cod}, denumire{denumire}, marime{marime}, pret{pret}, disponibila{disponibila} {};
    virtual ~Bicicleta() {

    }
    int getCod() const {
        return cod;
    }
    string getDenumire() const {
        return denumire;
    }
    string getMarime() const {
        return marime;
    }
    double getPret() const {
        return pret;
    }
    bool getDisponibila() const {
        return disponibila;
    }
    void operator=(const Bicicleta& other) {
        this->cod = other.cod;
        this->denumire = other.denumire;
        this->marime = other.marime;
        this->pret = other.pret;
        this->disponibila = other.disponibila;
    }

};


#endif //INCHIRIEREBICICLETE_BICICLETA_H
