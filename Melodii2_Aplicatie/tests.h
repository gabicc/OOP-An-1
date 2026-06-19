//
// Created by gabi on 6/19/26.
//

#ifndef MELODII2_APLICATIE_TESTS_H
#define MELODII2_APLICATIE_TESTS_H

#include "Melodie.h"
#include "Repo.h"
#include "Validator.h"
#include "Service.h"
#include <assert.h>

#endif //MELODII2_APLICATIE_TESTS_H
void test_domain() {
    Melodie m(1, "A", "B", "pop");
    assert(m.getId() == 1);
    assert(m.getTitlu() == "A");
    assert(m.getArtist() == "B");
    assert(m.getGen() == "pop");
}

void test_repo() {
    Repo repo("melodii.txt");
    Melodie m1(11, "A", "B", "pop");
    repo.addMelodie(m1);
    assert(repo.get_all_repo().size() == 11);
    Melodie m2(12, "dc", "aefe", "folk");
    repo.addMelodie(m2);
    assert(repo.get_all_repo().size() == 12);
    repo.removeMelodie(11);
    assert(repo.get_all_repo().size() == 11);
}

void test_validator() {
    Validator val;
    Melodie m1(1, "A", "B", "pop");
    val.validateMelodie(m1);
    Melodie m2(-1, "dc", "aefe", "folk");
    try {
        val.validateMelodie(m2);
        assert(false);
    }
    catch (ValidatorException& ve) {
        assert(true);
    }
    Melodie m3(1, "", "aefe", "folk");
    try {
        val.validateMelodie(m3);
        assert(false);
    }
    catch (ValidatorException& ve) {
        assert(true);
    }
    Melodie m4(1, "dc", "", "folk");
    try {
        val.validateMelodie(m4);
        assert(false);
    }
    catch (ValidatorException& ve) {
        assert(true);
    }
    Melodie m5(1, "dc", "aefe", "folk1");
    try {
        val.validateMelodie(m5);
        assert(false);
    }
    catch (ValidatorException& ve) {
        assert(true);
    }
}
void test_service() {
    Repo repo("melodii.txt");
    Validator val;
    Service srv(repo, val);
    string titlu1 = "A";
    string artist1 = "B";
    string gen1 = "pop";
    srv.addMelodie_srv(titlu1, artist1, gen1);
    assert(srv.get_all_srv().size() == 11);
    string titlu2 = "dc";
    string artist2 = "asrews";
    string gen2 = "folk";
    srv.addMelodie_srv(titlu2, artist2, gen2);
    assert(srv.get_all_srv().size() == 12);
    srv.removeMelodie_srv(1);
    assert(srv.get_all_srv().size() == 11);
}

void test_all() {
    test_domain();
    test_repo();
    test_validator();
    test_service();
}