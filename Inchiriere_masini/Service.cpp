//
// Created by gabi on 3/30/26.
//

#include "Service.h"
#include "Validator.h"
#include <algorithm>

Service::Service(RepoMasini& repo):repo(repo) {
}
Service::~Service() {

}
void Service::adaugaMasina_srv(const Masina& m) {
    validator.validate_masina(m);
    repo.adaugaMasina(m);
}
void Service::stergeMasina_srv(const string& nrInmatric) {
    repo.stergeMasina(nrInmatric);
}
void Service::modificaMasina_srv(const string& nrInamtriculare_vechi, const string& nrInamtriculare_nou) {
    repo.modificaMasina(nrInamtriculare_vechi, nrInamtriculare_nou);
}
void Service::afis_Masini_srv() {
    repo.afis_Masini();
}

vector<Masina> Service::filtreaza_dupa_producator_srv(const string& producator) const {
    vector<Masina> all = repo.get_all();
    vector<Masina> filtered;
    for (const auto& masina : all) {
        if (masina.get_producator() == producator) {
            filtered.push_back(masina);
        }
    }
    return filtered;
}

vector<Masina> Service::filtreaza_dupa_tip_srv(const string& tip) const {
    vector<Masina> all = repo.get_all();
    vector<Masina> filtered;
    for (const auto& masina : all) {
        if (masina.get_tip() == tip) {
            filtered.push_back(masina);
        }
    }
    return filtered;
}

vector<Masina> Service::sorteaza_dupa_nr_inmatriculare_srv() const {
    vector<Masina> sorted = repo.get_all();
    sort(sorted.begin(), sorted.end(), [](const Masina& m1, const Masina& m2) {
        return m1.get_nr_inmatriculare() < m2.get_nr_inmatriculare();
    });
    return sorted;
}

vector<Masina> Service::sorteaza_dupa_tip_srv() const {
    vector<Masina> sorted = repo.get_all();
    sort(sorted.begin(), sorted.end(), [](const Masina& m1, const Masina& m2) {
        if (m1.get_tip() == m2.get_tip()) {
            return m1.get_nr_inmatriculare() < m2.get_nr_inmatriculare();
        }
        return m1.get_tip() < m2.get_tip();
    });
    return sorted;
}

vector<Masina> Service::sorteaza_dupa_producator_model_srv() const {
    vector<Masina> sorted = repo.get_all();
    sort(sorted.begin(), sorted.end(), [](const Masina& m1, const Masina& m2) {
        if (m1.get_producator() == m2.get_producator()) {
            if (m1.get_model() == m2.get_model()) {
                return m1.get_nr_inmatriculare() < m2.get_nr_inmatriculare();
            }
            return m1.get_model() < m2.get_model();
        }
        return m1.get_producator() < m2.get_producator();
    });
    return sorted;
}

int Service::nr_masini() {
    return repo.masini.getLung();
}