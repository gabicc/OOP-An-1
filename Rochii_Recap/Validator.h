//
// Created by gabi on 6/13/26.
//

#ifndef ROCHII_RECAP_VALIDATOR_H
#define ROCHII_RECAP_VALIDATOR_H
#include <exception>
#include <string>
#include <vector>

class Rochie;
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
    vector<string> errorMsg;
public:
    void validateRochie(Rochie& r);
};


#endif //ROCHII_RECAP_VALIDATOR_H
