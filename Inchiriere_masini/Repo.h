//
// Created by gabi on 4/28/26.
//

#ifndef INCHIRIERE_MASINI_REPO_H
#define INCHIRIERE_MASINI_REPO_H

/*
creati o clasa pur abstracta Repo si un nou repo. Aplicatia trebuie sa porneasca si cu
acest repo, pe langa cel pe care il aveti (pe rand). Repo nou sa tina datele intr-un
dictionar (map, unordered_map). La constructor sa primeasca o probabilitate (o valoarea
intre 0 si 1) si daca apelam orice metoda din repo, metoda sa arunce exceptie cu
probabilitatea data.
*/

#include <map>
#include <string>
#include "Masina.h"

using namespace std;

class Repo {
    friend class Service;
private:
    map<string, Masina> masini;
    double probabilitate_aruncare_exceptie;

    void arunca_exceptie_random() const;
public:
    Repo(double probabilitate_aruncare_exceptie);
    virtual ~Repo();
    virtual void addMasina(const string& nrInmatric, const string& producator, const string& model, const string& tip) = 0;
    virtual void removeMasina(const string& nrInmatric) = 0;
    virtual void modifyMasina(const string& nrInmatric_vechi, const string& nrInmatric_nou) = 0;
};



#endif //INCHIRIERE_MASINI_REPO_H
