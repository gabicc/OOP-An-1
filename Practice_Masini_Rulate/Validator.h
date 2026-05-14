//
// Created by gabi on 5/14/26.
//

#ifndef PRACTICE_MASINI_RULATE_VALIDATOR_H
#define PRACTICE_MASINI_RULATE_VALIDATOR_H

#include <iostream>
#include "Masina.h"
#include <vector>
#include <string.h>

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
    vector<string> errorMsg;
public:
    void validateMasina(Masina m);
    string getErrorMsg() {
        string fullMsg = "";
        for (string e: errorMsg) {
            fullMsg += e + '\n';
        }
        return fullMsg;
    }
};


#endif //PRACTICE_MASINI_RULATE_VALIDATOR_H
