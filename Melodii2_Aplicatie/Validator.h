//
// Created by gabi on 6/19/26.
//

#ifndef MELODII2_APLICATIE_VALIDATOR_H
#define MELODII2_APLICATIE_VALIDATOR_H

#include <iostream>
#include <string.h>
#include <vector>
#include "Melodie.h"
#include <fstream>
#include <sstream>
#include "Melodie.h"

class ValidatorException: public exception {
private:
    string errorMessage;
public:
    ValidatorException(string errmrMsg): errorMessage{errmrMsg} {};
    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};

class Validator {
public:
    void validateMelodie(Melodie m);
};


#endif //MELODII2_APLICATIE_VALIDATOR_H
