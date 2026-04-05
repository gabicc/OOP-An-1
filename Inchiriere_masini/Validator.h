//
// Created by gabi on 4/5/26.
//

#ifndef INCHIRIERE_MASINI_VALIDATOR_H
#define INCHIRIERE_MASINI_VALIDATOR_H
#include "Masina.h"

class ValidationException : public exception {
private:
    string message;
public:
    // Constructor
    ValidationException(string msg) : message(msg) {}

    // Override what() method
    const char* what() const noexcept override {
        return message.c_str();
    }

    // Optional: method to get the invalid value
    string getValue() const {
        return message;
    }
};


class Validator {
public:
    void validate_masina(const Masina& m);
};



#endif //INCHIRIERE_MASINI_VALIDATOR_H
