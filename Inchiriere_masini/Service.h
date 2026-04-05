//
// Created by gabi on 3/30/26.
//

#ifndef INCHIRIERE_MASINI_SERVICE_H
#define INCHIRIERE_MASINI_SERVICE_H

#include "RepoMasini.h"
#include "Validator.h"
class Service {
private:
    RepoMasini& repo;
    Validator validator;
public:
    Service(RepoMasini& repo);
    ~Service();
    void adaugaMasina_srv(const Masina& m);
    void stergeMasina_srv(const string& nrInmatric);
    void modificaMasina_srv(const string& nrInamtriculare_vechi, const string& nrInamtriculare_nou);
    void afis_Masini_srv();
    int nr_masini();
};

#endif //INCHIRIERE_MASINI_SERVICE_H
