#include "gtest/gtest.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Validator.h"
#include "Service.h"

TEST(UnitTestconcurs,TestValidator)
		{
			Participant p;

			strcpy(p.surname, "Popescu");
			strcpy(p.first_name, "Ion");
			p.score = 10;
			assert(validate_participant(&p) == 1);

			strcpy(p.surname, "");
			assert(validate_participant(&p) == 0);


			strcpy(p.surname, "Popescu");
			strcpy(p.first_name, "");
			assert(validate_participant(&p) == 0);

			strcpy(p.first_name, "Ion");
			p.score = -10;
			assert(validate_participant(&p) == 0);
		}


TEST(UnitTestconcurs,test_add_participant)
		{

			ServiceConcurs srv;
			srv.repo.n = 0;

			add_participant_in_service(&srv, (char*)"Ion", (char*)"Vasile", 100);
			assert(srv.repo.n == 1);
			assert(strcmp(srv.repo.arr[0]->surname, "Ion") == 0);

			add_participant_in_service(&srv, (char*)"Ion", (char*)"Vasile", -5);
			assert(srv.repo.n == 1);
		}

		TEST(UnitTestconcurs,test_change_participant) {
			ServiceConcurs srv;
			srv.repo.n = 0;

			add_participant_in_service(&srv, (char*)"Ion", (char*)"Vasile", 100);
			assert(srv.repo.n == 1);

			change_participant_in_service(&srv, (char*)"Ion", (char*)"Vasile", 200);
			assert(srv.repo.arr[0]->score == 200);

			change_participant_in_service(&srv, (char*)"Ion", (char*)"Vasile", -10);
			assert(srv.repo.arr[0]->score == 200);
		}

		TEST(UnitTestconcurs,test_delete_participant) {
			ServiceConcurs srv;
			srv.repo.n = 0;

			add_participant_in_service(&srv, (char*)"Ion", (char*)"Vasile", 100);
			add_participant_in_service(&srv, (char*)"Ana", (char*)"Maria", 50);
			assert(srv.repo.n == 2);

			delete_participant_in_service(&srv, (char*)"Ion", (char*)"Vasile", 100);
			assert(srv.repo.n == 1);
			assert(strcmp(srv.repo.arr[0]->surname, "Ana") == 0);

			delete_participant_in_service(&srv, (char*)"X", (char*)"Y", 10);
			//printf("%d", srv.repo.n);
			assert(srv.repo.n == 1);
		}

