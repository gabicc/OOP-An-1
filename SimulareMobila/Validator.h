//
// Created by gabi on 5/19/26.
//

#ifndef SIMULAREMOBILA_VALIDATOR_H
#define SIMULAREMOBILA_VALIDATOR_H
#include <exception>
#include <iostream>
#include <vector>
#include "Mobila.h"

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
private:
    vector<string> errors;
public:
    Validator() {};
    ~Validator() {};
    void validateMobila(Mobila m);
};


#endif //SIMULAREMOBILA_VALIDATOR_H
