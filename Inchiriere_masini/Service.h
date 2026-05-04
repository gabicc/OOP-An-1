//
// Created by gabi on 3/30/26.
//

#ifndef INCHIRIERE_MASINI_SERVICE_H
#define INCHIRIERE_MASINI_SERVICE_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Masina.h"

using namespace std;

#include "RepoMasini.h"
#include "Validator.h"
class Service {
private:
    Repo* repo;
    Validator validator;
    vector<Masina> cos;
public:
    Service(Repo* repo);
    ~Service();
    void adaugaMasina_srv(const Masina& m);
    void stergeMasina_srv(const string& nrInmatric);
    void modificaMasina_srv(const string& nrInamtriculare_vechi, const string& nrInamtriculare_nou);
    void afis_Masini_srv();
    vector<Masina> filtreaza_dupa_producator_srv(const string& producator) const;
    vector<Masina> filtreaza_dupa_tip_srv(const string& tip) const;
    vector<Masina> sorteaza_dupa_nr_inmatriculare_srv() const;
    vector<Masina> sorteaza_dupa_tip_srv() const;
    vector<Masina> sorteaza_dupa_producator_model_srv() const;
    int nr_masini();
    void golire_srv();
    void Undo();

    void adaugaInCos(const string& nrInmatriculare);
    void golireCos();
    int nrMasiniCos() const;

    void exportCSV(const string& filename) const;

    map<string, int> statistica_pruducatori() const;
};

#endif //INCHIRIERE_MASINI_SERVICE_H
