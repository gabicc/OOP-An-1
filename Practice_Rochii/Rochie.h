//
// Created by gabi on 5/16/26.
//

#ifndef PRACTICE_ROCHII_ROCHIE_H
#define PRACTICE_ROCHII_ROCHIE_H


class Rochie {
private:
    int cod;
    char* denumire;
    char marime;
    double pret;
    bool disponibila;
public:
    Rochie(int cod, char* denumire, char marime, double pret, bool disponibila): cod{cod}, denumire{denumire}, marime{marime}, pret{pret}, disponibila{disponibila} {};
    ~Rochie();
    int getCod() const {

    }

};


#endif //PRACTICE_ROCHII_ROCHIE_H
