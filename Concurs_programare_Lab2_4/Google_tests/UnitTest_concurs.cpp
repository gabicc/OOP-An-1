#include "gtest/gtest.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "Validator.h"
#include "Service.h"
#include "Repo.h"

TEST(UnitTestconcurs, TestValidator) {
    Participant* p = create_participant((char*)"Popescu", (char*)"Ion", 10);
    assert(validate_participant(p) == V_OK);

    free(p->surname);
    p->surname = (char*)malloc(1);
    p->surname[0] = '\0';
    assert(validate_participant(p) != 0);

    free(p->surname);
    p->surname = (char*)malloc(strlen("Popescu") + 1);
    strcpy(p->surname, "Popescu");
    free(p->first_name);
    p->first_name = (char*)malloc(1);
    p->first_name[0] = '\0';
    assert(validate_participant(p) != 0);

    free(p->first_name);
    p->first_name = (char*)malloc(strlen("Ion") + 1);
    strcpy(p->first_name, "Ion");
    p->score = -10;
    assert(validate_participant(p) != 0);

    destroy_participant(p);
}


TEST(UnitTestconcurs, test_add_participant) {
    ServiceConcurs srv;
    //srv.repo.n = 0;
    init_service(&srv);

    add_participant_in_service(&srv, (char *) "Ion", (char *) "Vasile", 100);
    assert(srv.repo.n == 1);
    assert(strcmp(srv.repo.arr[0]->surname, "Ion") == 0);

    add_participant_in_service(&srv, (char *) "Ion", (char *) "Vasile", -5);
    assert(srv.repo.n == 1);
    destroy_service(&srv);
}

TEST(UnitTestconcurs, test_change_participant) {
    ServiceConcurs srv;
    //srv.repo.n = 0;
    init_service(&srv);

    add_participant_in_service(&srv, (char *) "Ion", (char *) "Vasile", 100);
    assert(srv.repo.n == 1);

    change_participant_in_service(&srv, (char *) "Ion", (char *) "Vasile", 200);
    assert(srv.repo.arr[0]->score == 200);

    change_participant_in_service(&srv, (char *) "Ion", (char *) "Vasile", -10);
    assert(srv.repo.arr[0]->score == 200);
}

TEST(UnitTestconcurs, test_delete_participant) {
    ServiceConcurs srv;
    //srv.repo.n = 0;
    init_service(&srv);

    add_participant_in_service(&srv, (char *) "Ion", (char *) "Vasile", 100);
    add_participant_in_service(&srv, (char *) "Ana", (char *) "Maria", 50);
    assert(srv.repo.n == 2);

    delete_participant_in_service(&srv, (char *) "Ion", (char *) "Vasile", 100);
    assert(srv.repo.n == 1);
    assert(strcmp(srv.repo.arr[0]->surname, "Ana") == 0);

    delete_participant_in_service(&srv, (char *) "X", (char *) "Y", 10);
    //printf("%d", srv.repo.n);
    assert(srv.repo.n == 1);
}

TEST(UnitTestconcurs, test_delete_invalid_participant) {
    ServiceConcurs srv;
    //srv.repo.n = 0;
    init_service(&srv);

    add_participant_in_service(&srv, (char *) "Ion", (char *) "Vasile", 100);
    add_participant_in_service(&srv, (char *) "Ana", (char *) "Maria", 50);
    add_participant_in_service(&srv, (char *) "Ion2", (char *) "Vasile2", 120);
    assert(srv.repo.n == 3);

    delete_participant_in_service(&srv, (char *) "Ion", (char *) "Vasile", -100);
    assert(srv.repo.n == 3);
    assert(strcmp(srv.repo.arr[1]->surname, "Ana") == 0);
}
