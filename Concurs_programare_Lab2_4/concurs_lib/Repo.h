#ifndef REPO_H
#define REPO_H
#include "Entities.h"

struct RepoParticipanti
{
    int n;          // număr elemente
    int capacity;   // capacitate alocată
    struct Participant** arr; // vector dinamic de pointeri la Participant
};

#ifdef __cplusplus
extern "C" {
#endif
/*
 * r - element de tip RepoParicipanti cu n, capacity si array de participanti
 * p - Participant
 */

struct RepoParticipanti* clone_repo(struct RepoParticipanti* r);
void init_repo(struct RepoParticipanti* r);
void destroy_repo(struct RepoParticipanti* r);

void add_participant(struct RepoParticipanti* r, struct Participant* p);

void change_participant(struct RepoParticipanti *r, struct Participant *p);

void delete_participant(struct RepoParticipanti* r, struct Participant* p);
/*
 * max_score - scor maxim pt filtrare
 * result - lista de participanti care au scor mai mic decat max_score
 * result_len - lungimea listei de result
 */
void filter_by_score(struct RepoParticipanti* r, int max_score, struct Participant** result, int* result_len);
/*
 * ascending - cum sa ordoneze, cresc/descresc
 */
void sort_by_name(struct RepoParticipanti* r, int ascending);
void sort_by_score(struct RepoParticipanti* r, int ascending);

#ifdef __cplusplus
}
#endif

#endif