//
// Created by gabi on 6/21/26.
//

#ifndef TASKSAPLICATIE_VALIDATOR_H
#define TASKSAPLICATIE_VALIDATOR_H

#include <exception>

#include <iostream>
#include <string.h>
#include <vector>
#include "Task.h"
#include <fstream>
#include <sstream>

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
public:
    void validateTask(Task t);
};


#endif //TASKSAPLICATIE_VALIDATOR_H
