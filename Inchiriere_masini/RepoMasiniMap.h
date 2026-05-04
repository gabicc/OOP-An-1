//
// Created by gabi on 3/30/26.
//

#ifndef INCHIRIERE_MASINI_REPOMASINIMAP_H
#define INCHIRIERE_MASINI_REPOMASINIMAP_H
#include <vector>

#include "ListaInlantuita.h"
#include "Masina.h"
#include "Undo.h"
#include "Repo.h"
#include <map>

class RepoMasiniMap: public Repo{
    friend class Service;
private:
    map<string, Masina> masini;
    vector<ActiuneUndo*> actiuni_undo;
    //void arunca_exceptie_random() const;
    double probabilitate_aruncare_exception;
    void arunca_exceptie_random() const;
public:
    RepoMasiniMap(double probabilitate_aruncare_exceptie);
    virtual ~RepoMasiniMap();
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

#endif //INCHIRIERE_MASINI_REPOMASINIMAP_H
