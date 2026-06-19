//
// Created by gabi on 6/18/26.
//

#ifndef MELODIIAPLICATIE_VALIDATOR_H
#define MELODIIAPLICATIE_VALIDATOR_H
#include <exception>

#include <iostream>
#include <string.h>
#include <vector>
#include "Repo.h"

#include "Melodie.h"

class ValidatorException: public std::exception {
private:
    string errorMsg;
public:
    ValidatorException(string errroMessage): errorMsg{errroMessage} {};
    const char* what() const noexcept override {
        return errorMsg.c_str();
    }
};

class Validator {
private:
    Repo repo;
public:
    Validator(Repo repo): repo{repo} {};
    void validateMelodie(Melodie m);
};


#endif //MELODIIAPLICATIE_VALIDATOR_H
