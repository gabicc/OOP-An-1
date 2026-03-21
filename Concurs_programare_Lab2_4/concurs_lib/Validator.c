#include "Validator.h"
#include <string.h>

int validate_participant(struct Participant* p) {
	/*
	 * Se valideaza participantul p, se verifica daca numele, prenumele sunt nenule si nu sunt goale, si daca scorul este pozitiv
	 */
	if (p->surname == NULL || strlen(p->surname) == 0)
		return 0;
	if (p->first_name == NULL || strlen(p->first_name) == 0)
		return 0;
	if (p->score < 0)
		return 0;
	return 1;
}