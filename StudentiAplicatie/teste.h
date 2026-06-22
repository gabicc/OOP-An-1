//
// Created by gabi on 6/22/26.
//

#ifndef STUDENTIAPLICATIE_TESTE_H
#define STUDENTIAPLICATIE_TESTE_H

#include <iostream>
#include <string>
#include "Student.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>
#include "Repo.h"
#include "Validator.h"
#include "Service.h"
#include <assert.h>

using namespace std;

void test_domain() {
    Student s(1, "A", 18, "mate");
    assert(s.getNrMatricol() == 1);
    assert(s.getNume() == "A");
    assert(s.getVarsta() == 18);
    assert(s.getFacultate() == "mate");
}

void test_repo() {
    Repo repo("studenti.txt");
    assert(repo.get_all_repo().size() == 10);
    repo.removeStudent(1);
    assert(repo.get_all_repo().size() == 9);
    repo.undo();
    assert(repo.get_all_repo().size() == 10);
    repo.redo();
    assert(repo.get_all_repo().size() == 9);
    repo.intinerire_repo();
    assert(repo.get_all_repo()[0].getVarsta() == 18);
}

void test_validator() {
    Validator val;
    Student s1(-1, "A", 18, "mate");
    Student s2(1, "", 18, "mate");
    Student s3(1, "A", -18, "mate");
    Student s4(1, "A", 18, "mate1");
    try {
        val.validateStudent(s1);
        assert(false);
    }
    catch (ValidatorException& ve) {
        assert(true);
    }
    try {
        val.validateStudent(s2);
        assert(false);
    }
    catch (ValidatorException& ve) {
        assert(true);
    }
    try {
        val.validateStudent(s3);
        assert(false);
    }
    catch (ValidatorException& ve) {
        assert(true);
    }
    try {
        val.validateStudent(s4);
        assert(false);
    }
    catch (ValidatorException& ve) {
        assert(true);
    }
}

void test_service() {
    Repo repo("studenti.txt");
    Validator val;
    Service srv(repo, val);
    vector<Student> all = srv.get_all_srv();
    assert(srv.get_all_srv().size() == 10);
    srv.removeStudent_srv(1);
    assert(srv.get_all_srv().size() == 9);
    assert(all[0].getNrMatricol() == 5);
    assert(all[9].getNrMatricol() == 8);
}


void test_all() {
    test_domain();
    test_repo();
    test_validator();
    test_service();
}

#endif //STUDENTIAPLICATIE_TESTE_H
