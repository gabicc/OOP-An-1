//
// Created by gabi on 6/13/26.
//

#ifndef ROCHII_RECAP_ROCHIE_H
#define ROCHII_RECAP_ROCHIE_H
#include <string>

using namespace std;

class Rochie {
private:
    int cod;
    string denumire;
    int marime;
    double pret;
    bool disponibila;
public:
    Rochie(int cod, string denumire, int marime, double pret, bool disponibila):
    cod{cod}, denumire{denumire}, marime{marime}, pret{pret}, disponibila{disponibila} {};
    int getCod() const {
        return this->cod;
    }
    string getDenumire() const {
        return denumire;
    }
    int getMarime() const {
        return marime;
    }
    double getPret() const {
        return pret;
    }
    bool getDisponibilitate() const {
        return disponibila;
    }
    void operator=(const Rochie& other) {
        cod = other.cod;
        denumire = other.denumire;
        marime = other.marime;
        pret = other.pret;
        disponibila = other.disponibila;
    }
};


#endif //ROCHII_RECAP_ROCHIE_H
