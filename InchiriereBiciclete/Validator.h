//
// Created by gabi on 5/17/26.
//

#ifndef INCHIRIEREBICICLETE_VALIDATOR_H
#define INCHIRIEREBICICLETE_VALIDATOR_H
#include <exception>
#include <string.h>
#include <iostream>
#include <vector>
#include "Bicicleta.h"

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
    virtual ~Validator() {

    }
    void validate(Bicicleta& b);
};


#endif //INCHIRIEREBICICLETE_VALIDATOR_H
