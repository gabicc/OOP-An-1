//
// Created by gabi on 3/30/26.
//

#ifndef INCHIRIERE_MASINI_REPOMASINI_H
#define INCHIRIERE_MASINI_REPOMASINI_H
#include <vector>

#include "ListaInlantuita.h"
#include "Masina.h"
#include "Undo.h"

class RepoMasini {
    friend class Service;
private:
    vector<Masina> masini;
    vector<ActiuneUndo*> actiuni_undo;
public:
    RepoMasini();
    virtual ~RepoMasini();
    void adaugaMasina(const Masina& m);
    void stergeMasina(const string& nrInmatric);
    void modificaMasina(const string& nrInamtriculare_vechi, const string& nrInamtriculare_nou);
    void afis_Masini();
    void Undo();
    vector<Masina> get_all() const;
    void golire_repo();

    vector<Masina> filtreaza_dupa_pruducator(const string& producator) const;
    vector<Masina> filtreaza_dupa_tip(const string& tip) const;
};

#endif //INCHIRIERE_MASINI_REPOMASINI_H
