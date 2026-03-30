#include "Entities.h"

#include <stdlib.h>
#include <string.h>

struct Participant* create_participant(char* surname, char* first_name, int score) {
    struct Participant* p = (struct Participant*)malloc(sizeof(struct Participant));
    if (!p) return NULL;

    p->surname = NULL;
    p->first_name = NULL;
    p->score = score;

    p->surname = (char*)malloc(strlen(surname) + 1);
    if (!p->surname) {
        free(p);
        return NULL;
    }
    strcpy(p->surname, surname);

    p->first_name = (char*)malloc(strlen(first_name) + 1);
    if (!p->first_name) {
        free(p->surname);
        free(p);
        return NULL;
    }
    strcpy(p->first_name, first_name);

    return p;
}

struct Participant* clone_participant(struct Participant* p) {
    struct Participant* clone;
    clone = (struct Participant*) malloc(sizeof(struct Participant));
    //memcpy(clone, p, sizeof(struct Participant));
    strcpy(clone->surname, p->surname);
    strcpy(clone->first_name, p->first_name);
    clone->score = p->score;
    return clone;
}

void destroy_participant(struct Participant* p) {
    if (!p) return;
    free(p->surname);
    free(p->first_name);
    free(p);
}
