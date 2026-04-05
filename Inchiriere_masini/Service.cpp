//
// Created by gabi on 3/30/26.
//

#include "Service.h"
#include "Validator.h"

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

int Service::nr_masini() {
    return repo.masini.getLung();
}