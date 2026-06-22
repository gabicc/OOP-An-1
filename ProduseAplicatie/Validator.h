//
// Created by gabi on 6/20/26.
//

#ifndef PRODUSEAPLICATIE_VALIDATOR_H
#define PRODUSEAPLICATIE_VALIDATOR_H
#include <exception>

#include <iostream>
#include <string.h>
#include "Produs.h"

using namespace std;

class ValidatorException: public std::exception {
private:
    string errorMsg;
public:
    ValidatorException(string errorMessage): errorMsg{errorMessage} {};
    const char* what() const noexcept override {
        return errorMsg.c_str();
    }
};

class Validator {
public:
    void validateProdus(Produs p);
};


#endif //PRODUSEAPLICATIE_VALIDATOR_H
