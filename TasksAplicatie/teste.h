//
// Created by gabi on 6/21/26.
//

#ifndef TASKSAPLICATIE_TESTE_H
#define TASKSAPLICATIE_TESTE_H

#include <exception>

#include <iostream>
#include <string.h>
#include <vector>
#include "Task.h"
#include <fstream>
#include <sstream>
#include "Repo.h"
#include "Validator.h"
#include <assert.h>
#include "Service.h"

using namespace std;

void test_domain() {
    Task t1(1, "A", {"a", "b", "c"}, "open");
    assert(t1.getId() == 1);
    assert(t1.getDescriere() == "A");
    vector<string> programatori = t1.getProgramatori();
    assert(programatori[0] == "a");
    assert(programatori[1] == "b");
    assert(t1.getStare() == "open");
}
void test_repo() {
    Repo repo("tasks.txt");
    Task t1(101, "A", {"a", "b", "c"}, "open");
    Task t2(102, "A", {"a", "b", "c"}, "open");
    repo.addTask(t1);
    assert(repo.get_all_repo().size() == 11);
    repo.addTask(t2);
    assert(repo.get_all_repo().size() == 12);
    vector<Task> gasiti = repo.find_programator("a");
    // Task t3(1,"A",{"a","b","c","d"},"open");
    assert(gasiti[0].getId() == 1);
    repo.modifyStare(t1, "inprogress");
    for (Task& t: repo.get_all_repo()) {
        if (t.getId() == t1.getId())
            assert(t.getStare() == "inprogress");
    }
}

void test_validator() {
    Validator val;
    Task t1(101, "", {"a", "b", "c"}, "open");
    Task t2(102, "A", {"a", "b", "c", "d", "e"}, "open");
    Task t3(1,"A",{"a","b","c","d"},"open111");
    try {
        val.validateTask(t1);
        assert(false);
    }catch (ValidatorException& ve) {
        assert(true);
    }
    try {
        val.validateTask(t2);
        assert(false);
    }catch (ValidatorException& ve) {
        assert(true);
    }
    try {
        val.validateTask(t3);
        assert(false);
    }catch (ValidatorException& ve) {
        assert(true);
    }
}
void test_service() {
    Repo repo("tasks.txt");
    Validator val;
    Service srv(repo, val);
    Task t1(101, "A", {"a", "b", "c"}, "open");
    Task t2(102, "A", {"a", "b", "c"}, "open");
    srv.addTask_srv(101, "A", {"a", "b", "c"}, "open");
    assert(srv.get_all_srv().size() == 11);
    srv.addTask_srv(102, "A", {"a", "b", "c"}, "open");
    assert(srv.get_all_srv().size() == 12);
    vector<Task> gasiti = srv.findProgramator_srv("a");
    // Task t3(1,"A",{"a","b","c","d"},"open");
    assert(gasiti[0].getId() == 1);
    srv.modifyTask_srv(t1, "inprogress");
    for (Task& t: srv.get_all_srv()) {
        if (t.getId() == t1.getId())
            assert(t.getStare() == "inprogress");
    }
}

void test_all() {
    test_domain();
    test_repo();
    test_validator();
    test_service();
}

#endif //TASKSAPLICATIE_TESTE_H
