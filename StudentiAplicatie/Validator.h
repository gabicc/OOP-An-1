//
// Created by gabi on 6/22/26.
//

#ifndef STUDENTIAPLICATIE_VALIDATOR_H
#define STUDENTIAPLICATIE_VALIDATOR_H

#include <iostream>
#include <string>
#include "Student.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>

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
    void validateStudent(Student s);
};



#endif //STUDENTIAPLICATIE_VALIDATOR_H
