//
// Created by gabi on 5/12/26.
//

#ifndef INCHIRIEREROCHII_REPO_H
#define INCHIRIEREROCHII_REPO_H

#include "Rochie.h"
#include <vector>
#include <iostream>

using namespace std;

class Repo {
private:
    Rochie* rochii;
    int size;
    int capacity;
public:
    Repo();
    ~Repo();
    void addRochie(Rochie r);
    void removeRochie(int cod);
    void updateRochie(int cod, Rochie r_nou);
    void afisRochii();
    void resize();
};


#endif //INCHIRIEREROCHII_REPO_H
