//
// Created by gabi on 3/30/26.
//

#ifndef INCHIRIERE_MASINI_REPOMASINI_H
#define INCHIRIERE_MASINI_REPOMASINI_H
#include <vector>
#include "Masina.h"

class RepoMasini {
private:
    vector<Masina> masini;
public:
    RepoMasini();
    virtual ~RepoMasini();
    void adaugaMasina(const Masina& m);
    void stergeMasina(const string& nrInmatric);
    void modificaMasina(const string& nrInamtriculare_vechi, const string& nrInamtriculare_nou);
    void afis_Masini();
};

#endif //INCHIRIERE_MASINI_REPOMASINI_H
