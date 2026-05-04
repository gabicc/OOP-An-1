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
public:
    virtual ~Repo(){};
    virtual void adaugaMasina(const Masina& m) = 0;
    virtual void stergeMasina(const string& nrInmatric) = 0;
    virtual void modificaMasina(const string& nrInamtriculare_vechi, const string& nrInamtriculare_nou) = 0;
    virtual void afis_Masini() = 0;
    virtual void Undo() = 0;
    virtual vector<Masina> get_all() const = 0;
    virtual void golire_repo() = 0;

    virtual vector<Masina> filtreaza_dupa_pruducator(const string& producator) const = 0;
    virtual vector<Masina> filtreaza_dupa_tip(const string& tip) const = 0;
};



#endif //INCHIRIERE_MASINI_REPO_H
