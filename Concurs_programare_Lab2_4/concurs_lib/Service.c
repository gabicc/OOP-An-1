#include "Service.h"
#include <stdlib.h>
#include "Validator.h"
#include <stdio.h>
#include <string.h>

void init_service(struct ServiceConcurs* srv) {
	/*
	 * Se initializeaza repo-ul din srv, se apeleaza init_repo pentru a aloca memoria necesara pentru repo
	 */
	init_repo(&srv->repo);
}

void destroy_service(struct ServiceConcurs* srv) {
	/*
	 * Se distruge repo-ul din srv, se apeleaza destroy_repo pentru a elibera memoria alocata pentru repo
	 */
	destroy_repo(&srv->repo);
}
void add_participant_in_service(struct ServiceConcurs* srv, char* surname, char* first_name, int score) {
	/*
	 * Se creeaza un participant cu numele, prenumele si scorul dat ca parametru, se valideaza participantul, daca este valid,
	 * se adauga in repo-ul din srv, daca nu este valid, se afiseaza un mesaj de eroare
	 */
	struct Participant* p = create_participant(surname, first_name, score);
	if (!p) {
		printf("Error: memory allocation failed\n");
		return;
	}


	enum ValidationCodes err = validate_participant(p);
	if (err != V_OK) {
		printf("Error: invalid participant (cod %d)\n", err);
		destroy_participant(p);
		return;
	}
	add_participant(&(srv->repo), p);
}

void change_participant_in_service(struct ServiceConcurs* srv, char* surname, char* first_name, int score) {
	/*
	 * Se creeaza un participant cu numele, prenumele si scorul dat ca parametru, se valideaza participantul, daca este valid,
	 * se cauta participantul cu acelasi nume si prenume in repo-ul din
	 */
	struct Participant* p = create_participant(surname, first_name, score);
	if (!p) {
		printf("Error: memory allocation failed\n");
		return;
	}

	enum ValidationCodes err = validate_participant(p);
	if (err != V_OK) {
		printf("Error: invalid participant (cod %d)\n", err);
		destroy_participant(p);
		return;
	}
	change_participant(&(srv->repo), p);
}

void delete_participant_in_service(struct ServiceConcurs* srv, char* surname, char* first_name, int score) {
	/*
	 * Se creeaza un participant cu numele, prenumele si scorul dat ca parametru, se valideaza participantul, daca este valid,
	 * se cauta participantul cu acelasi nume si prenume in repo-ul din srv, daca se gaseste, se sterge din repo,
	 * daca nu se gaseste, se afiseaza un mesaj de eroare
	 */
	struct Participant* p = create_participant(surname, first_name, score);
	if (!p) {
		printf("Error: memory allocation failed\n");
		return;
	}


	enum ValidationCodes err = validate_participant(p);
	if (err != V_OK) {
		printf("Error: invalid participant (cod %d)\n", err);
		destroy_participant(p);
		return;
	}

	delete_participant(&(srv->repo), p);
	destroy_participant(p);
}
void filter_participants_by_score(struct ServiceConcurs* srv, int max_score) {
	/*
	 * Se creeaza o lista de participanti care au scorul mai mic decat max_score, se apeleaza filter_by_score pentru a umple aceasta lista,
	 * se afiseaza participantii din lista, daca nu exista niciun participant cu scorul mai mic decat max_score, se afiseaza un mesaj corespunzator
	 */
	struct Participant* result[20];
	int result_len = 0;

	filter_by_score(&(srv->repo), max_score, result, &result_len);

	printf("Participanti cu scor < %d:\n", max_score);
	for (int i = 0; i < result_len; i++) {
		struct Participant* p = result[i];
		printf("%s %s %d\n", p->surname, p->first_name, p->score);
	}
}

void sort_participants(struct ServiceConcurs* srv, int by_name, int ascending) {
	/*
	 * Se sorteaza participantii din repo-ul din srv, daca by_name este diferit de 0, se sorteaza dupa nume, altfel se sorteaza dupa scor,
	 * in functie de ascending (1 = crescator, 0 = descrescator)
	 */
	if (by_name)
		sort_by_name(&(srv->repo), ascending);
	else
		sort_by_score(&(srv->repo), ascending);
}

