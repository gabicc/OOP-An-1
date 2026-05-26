//
// Created by gabi on 5/18/26.
//

#ifndef PROCESORSIPLACADEBAZA_VALIDATOR_H
#define PROCESORSIPLACADEBAZA_VALIDATOR_H

#include <vector>
#include "Repo.h"
#include "Procesor.h"
#include "PlacaDeBaza.h"
#include <iostream>

using namespace std;

class ValidatorException: public exception {
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
    Validator() {

    }
    ~Validator() {

    }
    void validate_placa(PlacaDeBaza& p);
};


#endif //PROCESORSIPLACADEBAZA_VALIDATOR_H
