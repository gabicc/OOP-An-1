#include "Repo.h"
#include <stdlib.h>
#include <string.h>

void init_repo(struct RepoParticipanti* r) {
    /*
     * n - lungime r
     * capacity - capacitate r
     * arr - lista de participanti
     */
    r->n = 0;
    r->capacity = 2;
    r->arr = (struct Participant**)malloc(sizeof(struct Participant*) * r->capacity);
}

void destroy_repo(struct RepoParticipanti* r) {
    for (int i = 0; i < r->capacity; i++)
        free(r->arr[i]);
    free(r->arr);
}

static void ensure_capacity(struct RepoParticipanti* r) {
    /*
     * daca n trece de capacity, atunci se dubleaza capacitatea si se realoca memoria pentru arr
     */
    if (r->n < r->capacity)
        return;

    r->capacity *= 2;
    r->arr = (struct Participant**)realloc(r->arr, sizeof(struct Participant*) * r->capacity);
}

void add_participant(struct RepoParticipanti* r, struct Participant* p) {
    /*
     * se adauga participantul p in repo r, daca n trece de capacity, se dubleaza capacitatea si se realoca memoria pentru arr
     */
    ensure_capacity(r);
    r->arr[r->n++] = p;
}

void change_participant(struct RepoParticipanti* r, struct Participant* p) {
    /*
     * se cauta participantul cu acelasi nume si prenume ca p, daca se gaseste, se inlocuieste cu p
     */
    for (int i = 0; i < r->n; i++) {
        if (strcmp(r->arr[i]->surname, p->surname) == 0 &&
            strcmp(r->arr[i]->first_name, p->first_name) == 0) {

            free(r->arr[i]);
            r->arr[i] = p;
            return;
        }
    }
}

void delete_participant(struct RepoParticipanti* r, struct Participant* p) {
    /*
     * se cauta participantul cu acelasi nume si prenume ca p, daca se gaseste, se sterge din repo r
     */
    for (int i = 0; i < r->n; i++) {
        if (strcmp(r->arr[i]->surname, p->surname) == 0 &&
            strcmp(r->arr[i]->first_name, p->first_name) == 0) {

            free(r->arr[i]);

            for (int j = i + 1; j < r->n; j++)
                r->arr[j - 1] = r->arr[j];

            r->n--;
            return;
        }
    }
}

void filter_by_score(struct RepoParticipanti* r, int max_score, struct Participant** result, int* result_len) {
    /*
     * se filtreaza participantii din repo r care au scorul mai mic decat max_score
     */
    *result_len = 0;
    for (int i = 0; i < r->n; i++) {
        if (r->arr[i]->score < max_score) {
            result[*result_len] = r->arr[i];
            (*result_len)++;
        }
    }
}

void sort_by_name(struct RepoParticipanti* r, int ascending) {
    /*
     * se sorteaza participantii din repo r dupa nume, in functie de ascending (1 = crescator, 0 = descrescator)
     */
    for (int i = 0; i < r->n - 1; i++)
        for (int j = i + 1; j < r->n; j++) {
            int cmp = strcmp(r->arr[i]->surname, r->arr[j]->surname);
            if ((ascending && cmp > 0) || (!ascending && cmp < 0)) {
                struct Participant* aux = r->arr[i];
                r->arr[i] = r->arr[j];
                r->arr[j] = aux;
            }
        }
}

void sort_by_score(struct RepoParticipanti* r, int ascending) {
    /*
     * se sorteaza participantii din repo r dupa scor, in functie de ascending (1 = crescator, 0 = descrescator)
     */
    for (int i = 0; i < r->n - 1; i++)
        for (int j = i + 1; j < r->n; j++) {
            if ((ascending && r->arr[i]->score > r->arr[j]->score) ||
                (!ascending && r->arr[i]->score < r->arr[j]->score)) {
                struct Participant* aux = r->arr[i];
                r->arr[i] = r->arr[j];
                r->arr[j] = aux;
            }
        }
}
