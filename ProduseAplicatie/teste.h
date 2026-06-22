//
// Created by gabi on 6/20/26.
//

#ifndef PRODUSEAPLICATIE_TESTE_H
#define PRODUSEAPLICATIE_TESTE_H

#endif //PRODUSEAPLICATIE_TESTE_H

#include "Produs.h"
#include "Repo.h"
#include "Service.h"
#include "Validator.h"
#include <assert.h>

void test_domain() {
    Produs p(1, "A", "B", 12.5);
    assert(p.getId() == 1);
    assert(p.getNume() == "A");
    assert(p.getTip() == "B");
    assert(p.getPret() == 12.5);
}

void test_repo() {
    Repo repo("Produse.txt");
    Produs p1(11, "Abc", "Bbc", 12.5);
    Produs p2(12, "efg", "Bcd", 12.5);
    Produs p3(13, "wefew", "wefgewfc", 12.5);
    repo.addProdus(p1);
    assert(repo.get_all_repo().size() == 11);
    repo.addProdus(p2);
    assert(repo.get_all_repo().size() == 12);
    vector<Produs> produse = repo.get_all_repo();
    assert(produse[10].getId() == 11);
}
void test_validator() {
    Validator val;
    Produs p1(-11, "Abc", "Bbc", 12.5);
    Produs p2(12, "", "Bcd", 12.5);
    Produs p3(13, "wefew", "wefgewfc", 102.5);
    try {
        val.validateProdus(p1);
        assert(false);
    }catch (exception& e) {
        assert(true);
    }
    try {
        val.validateProdus(p2);
        assert(false);
    }catch (exception& e) {
        assert(true);
    }
    try {
        val.validateProdus(p3);
        assert(false);
    }catch (exception& e) {
        assert(true);
    }
}
void test_service() {
    Repo repo("Produse.txt");
    Validator val;
    Service srv(repo, val);
    // Produs p1(11, "Abc", "Bbc", 12.5);
    // Produs p2(12, "efg", "Bcd", 12.5);
    // Produs p3(13, "wefew", "wefgewfc", 12.5);
    srv.addProdus_srv(11, "Abc", "Bbc", 12.5);
    assert(srv.get_all_srv().size() == 11);
    srv.addProdus_srv(12, "efg", "Bcd", 13.5);
    assert(srv.get_all_srv().size() == 12);
    vector<Produs> produse = srv.get_all_srv();
    assert(produse[0].getId() == 11);// sunt ordonate dupa pret
}

void test_all() {
    test_domain();
    test_repo();
    test_validator();
    test_service();
}