//
// Created by gabi on 5/12/26.
//

#ifndef INCHIRIEREROCHII_ROCHIE_H
#define INCHIRIEREROCHII_ROCHIE_H

#include <string.h>
#include <iostream>

using namespace std;

class Rochie {
private:
    int cod;
    string denumire;
    double marime;
    double pret;
    bool disponibil;
public:
    Rochie(): cod{0}, denumire{""}, marime{0}, pret{0}, disponibil{false} {};
    Rochie(int cod, const string denumire, double marime, double pret, bool disponibil): cod{cod}, denumire{denumire}, marime{marime}, pret{pret}, disponibil{disponibil} {};
    ~Rochie();
    int get_cod();
    const string get_denumire();
    double get_marime();
    double get_pret();
    bool get_disponibil();
    void operator=(const Rochie& other);

};


#endif //INCHIRIEREROCHII_ROCHIE_H
