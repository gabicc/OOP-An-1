#ifndef  ENTITIES_H
#define ENTITIES_H

struct Participant
{
	char *surname;
	char *first_name;
	int score;
};

struct Participant* create_participant(char* surname, char* first_name, int score);
struct Participant* clone_participant(struct Participant* p);
void destroy_participant(struct Participant* p);
#endif
