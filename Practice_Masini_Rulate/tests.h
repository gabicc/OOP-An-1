//
// Created by gabi on 5/16/26.
//

#ifndef PRACTICE_MASINI_RULATE_TESTS_H
#define PRACTICE_MASINI_RULATE_TESTS_H

#include "Masina.h"
#include "Repo.h"
#include "Service.h"
#include <assert.h>

void testDomain() {
    Masina m{"CJ19DGC", "Dacia Logan", "rosu", 100000};
    assert(m.getNrMatricol() == "CJ19DGC");
    assert(m.getModel() == "Dacia Logan");
    assert(m.getCuloare() == "rosu");
    assert(m.getKm() == 100000);
}

void testRepoGetAll() {
    Repo repo("Masini.txt");
    vector<Masina> masini = repo.get_all_repo();
    assert(masini.size() == 7);
    Masina m6{"RG24DGC","Opel","Argintiu",9500};
    assert(m6.getNrMatricol() == "RG24DGC");
    assert(m6.getModel() == "Opel");
    assert(m6.getCuloare() == "Argintiu");
    assert(m6.getKm() == 9500);
}

void testServiceGetAll() {
    Repo repo("Masini.txt");
    Validator val;
    Service srv{repo, val};
    vector<Masina> masini = srv.get_all_srv();
    assert(masini.size() == 7);
}

void testRepoFindByNrMatricol() {
    Repo repo("Masini.txt");
    Masina m = repo.find_by_nrMatricol("CJ20DGC");
    assert(m.getNrMatricol() == "CJ20DGC");
    assert(m.getModel() == "Volkswagen");
    assert(m.getCuloare() == "Negru");
    assert(m.getKm() == 12000);
}

void testServiceRentMasina() {
    Repo repo("Masini.txt");
    Validator val;
    Service srv{repo, val};
    srv.rentMasina_srv("CJ20DGC");
    vector<Masina> masini = srv.get_all_srv();
    assert(masini.size() == 6);
    assert(masini[1].getNrMatricol() == "CJ21DGC");
}

void testSrvSortNrMatricol() {
    Repo repo("Masini.txt");
    Validator val;
    Service srv{repo, val};
    vector<Masina> sorted = srv.sortareNrMatricol_srv();
    assert(sorted[0].getNrMatricol() == "AB22DGC");
    assert(sorted[6].getNrMatricol() == "RG24DGC");
}

void testSrvSortModel() {
    Repo repo("Masini.txt");
    Validator val;
    Service srv{repo, val};
    vector<Masina> sorted = srv.sortareModel_srv();
    assert(sorted[0].getModel() == "Fiat");
    assert(sorted[1].getModel() == "Hyundai");
}

void testALL() {
    testDomain();
    testRepoGetAll();
    testServiceGetAll();
    testRepoFindByNrMatricol();
    testServiceRentMasina();
    testSrvSortNrMatricol();
    testSrvSortModel();
}

#endif //PRACTICE_MASINI_RULATE_TESTS_H
