//
// Created by gabi on 3/30/26.
//

#ifndef INCHIRIERE_MASINI_REPOMASINI_H
#define INCHIRIERE_MASINI_REPOMASINI_H
#include <vector>

#include "ListaInlantuita.h"
#include "Masina.h"
#include "Undo.h"
#include "Repo.h"

class RepoException {
private:
    string errorMessage;
public:
    RepoException(string errorMsg): errorMessage{errorMsg} {};
    string getErrorMessage() const {
        return this->errorMessage;
    }
};

class RepoMasini: public Repo{
    friend class Service;
private:
    vector<Masina> masini;
    vector<ActiuneUndo*> actiuni_undo;
    //void arunca_exceptie_random() const;
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

    void filtreaza_si_sterge_dupa_producator(const string& producator);
    void filtreaza_si_sterge_dupa_tip(const string& tip);
};

#endif //INCHIRIERE_MASINI_REPOMASINI_H
