#ifndef SERVICE_H
#define SERVICE_H
#include "Repo.h"

struct ServiceConcurs {
    struct RepoParticipanti repo;
};

#ifdef __cplusplus
extern "C" {
#endif
/*
 * srv - element de tip ServiceConcurs cu un repo de participanti
 */
void init_service(struct ServiceConcurs* srv);
void destroy_service(struct ServiceConcurs* srv);

/*
 * surname - numele de familie al participantului
 * first_name - prenumele participantului
 * scor - scorul participantului
 */
void add_participant_in_service(struct ServiceConcurs* srv, char* surname, char* first_name, int score);
void change_participant_in_service(struct ServiceConcurs* srv, char* surname, char* first_name, int score);
void delete_participant_in_service(struct ServiceConcurs* srv, char* surname, char* first_name, int score);

/*
 * max_score - scorul maxim pentru filtrare, se vor afisa doar participantii care au scorul mai mic decat max_score
 */
void filter_participants_by_score(struct ServiceConcurs* srv, int max_score);

/*
 * ascending - indica cum sa se ordoneze participantii, cresc/descresc
 */
void sort_participants(struct ServiceConcurs* srv, int by_name, int ascending);


#ifdef __cplusplus
}
#endif

#endif
