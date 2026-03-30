#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "Entities.h"
#ifdef __cplusplus
extern "C" {
#endif

enum ValidationCodes {
    V_OK = 0,
    V_INVALID_SURNAME = 1,
    V_INVALID_FIRST_NAME = 2,
    V_INVALID_SCORE = 3
};

enum ValidationCodes validate_participant(struct Participant* p);


#ifdef __cplusplus
}
#endif

#endif
