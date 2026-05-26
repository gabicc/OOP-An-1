//
// Created by gabi on 5/18/26.
//

#ifndef UNTITLED4_TESTS_H
#define UNTITLED4_TESTS_H

#endif //UNTITLED4_TESTS_H
#include "Procesor.h"
#include "PlacaDeBaza.h"
#include "Repo.h"
#include "Service.h"
#include <assert.h>

void testProcesor() {
    Procesor p("Ab", 4, 123, 500);
    assert(p.getNume() == "Ab");
    assert(p.getNrThrd() == 4);
    assert(p.getSoclu() == 123);
    assert(p.getPret() == 500);
}

void testPlaca() {
    PlacaDeBaza p("Ab", 123, 500);
    assert(p.getNumePlaca() == "Ab");
    assert(p.getSocluPlaca() == 123);
    assert(p.getPretPlaca() == 500);
}

void testRepo() {
    Repo repo("Procesor.txt", "PlaciDeBaza.txt");
    PlacaDeBaza p("Ab", 123, 500);
    repo.addPlaca(p);
    assert(repo.get_all_placi_repo().size() == 6);
}

void testAll() {
    testProcesor();
    testPlaca();
    testRepo();
}
