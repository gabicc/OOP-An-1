// Concurs_programare_Lab2_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Service.h"
#include <stdio.h>
#include "Entities.h"
#include <string.h>

void print_menu() {
    /*
     * Afiseaza optiunile care pot fi efectuate
     */
    printf("1. Adauga participant\n");
    printf("2. Schimbare participant\n");
    printf("3. Sterge participant\n");
    printf("4. Afisare dupa proprietate\n");
    printf("5. Sortare crescatoare/descrescatoare dupa nume/scor\n");
    printf("6. Afiseaza participanti\n");
    printf("0. Exit\n");
}

void citeste_participant(char surname[21], char first_name[21], int *score) {
    printf("Name: ");
    scanf("%20s", surname);

    printf("\nFirst name: ");
    scanf("%20s", first_name);

    printf("\nScore: ");
    scanf("%d", score);
}


void show_participants(struct ServiceConcurs *srv) {
    /*
     * Afiseaza toti participantii din repo-ul srv, se afiseaza numele, prenumele si scorul fiecarui participant
     */
    for (int i = 0; i < srv->repo.n; i++) {
        struct Participant *p = srv->repo.arr[i];
        printf("list[%d]: %s, %s, %d\n", i, p->surname, p->first_name, p->score);
    }
}


int main(void) {
    struct ServiceConcurs srv;
    init_service(&srv);
    srv.repo.n = 0;

    while (1) {
        print_menu();
        printf("\n");
        int choice;
        printf("Alege o optiune: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char surname[21], first_name[21];
                int score;
                citeste_participant(surname, first_name, &score);
                add_participant_in_service(&srv, surname, first_name, score);
                break;
            }
            case 2: {
                char surname[21], first_name[21];
                int score;
                citeste_participant(surname, first_name, &score);
                change_participant_in_service(&srv, surname, first_name, score);
                break;
            }
            case 3: {
                char surname[21], first_name[21];
                int score;
                citeste_participant(surname, first_name, &score);
                delete_participant_in_service(&srv, surname, first_name, score);
                break;
            }
            case 4: {
                int max_score;
                printf("Afiseaza participantii cu scor mai mic decat: ");
                scanf("%d", &max_score);
                filter_participants_by_score(&srv, max_score);
                break;
            }
            case 5: {
                int type, order;
                printf("Sorteaza dupa: 1 = nume, 2 = scor: ");
                scanf("%d", &type);
                printf("Ordine: 1 = crescator, 2 = descrescator: ");
                scanf("%d", &order);

                sort_participants(&srv, type == 1, order == 1);
                printf("Sortare efectuata.\n");
                break;
            }
            case 6: {
                show_participants(&srv);
                break;
            }
            case 0: {
                destroy_service(&srv);
                return 0;
            }
            default: {
                printf("Nu e o optiune valida. Incearca din nou\n");
                break;
            }
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
