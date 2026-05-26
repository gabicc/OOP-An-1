//
// Created by gabi on 5/19/26.
//

#ifndef SIMULAREMOBILA_TESTS_H
#define SIMULAREMOBILA_TESTS_H

#include "Mobila.h"
#include "Repo.h"
#include <assert.h>
#include "Service.h"

void testMobila() {
    Mobila m(1, "bed", 10, 120);
    assert(m.getId() == 1);
    assert(m.getType() == "bed");
    assert(m.getNrPieces() == 10);
    assert(m.getAssemblyTime() == 120);
}

void testRepo() {
    Repo repo("Mobile.txt");
    Mobila m(11, "wardrobe", 123, 234);
    repo.addMobila(m);
    assert(repo.getAll_repo().size() == 8);
    vector<Mobila> sortedNrPieces = repo.sortareNrPieces();
    assert(sortedNrPieces[0].getNrPieces() == 5);
    vector<Mobila> sortedAssemblyTime = repo.sortareAssemblyTime();
    assert(sortedAssemblyTime[0].getAssemblyTime() == 50);
    vector<Mobila> filtered = repo.filtrareType("bed");
    assert(filtered.size() == 2);
}

void testService() {
    Repo repo("Mobile.txt");
    Validator val;
    Service srv(repo, val);
    Mobila m(11, "wardrobe", 123, 234);
    srv.addMobila_srv(m);
    assert(srv.getAll_srv().size() == 8);
    vector<Mobila> sortedNrPieces = srv.sortareNrPieces_srv();
    assert(sortedNrPieces[0].getNrPieces() == 5);
    vector<Mobila> sortedAssemblyTime = srv.sortareAssemblyTime_srv();
    assert(sortedAssemblyTime[0].getAssemblyTime() == 50);
    vector<Mobila> filtered = srv.filtrareType_srv("bed");
    assert(filtered.size() == 2);
}

void testAll() {
    testMobila();
    testRepo();
    testService();
}

#endif //SIMULAREMOBILA_TESTS_H