//
// Created by gabi on 5/12/26.
//

#ifndef INCHIRIEREROCHII_VALIDATOR_H
#define INCHIRIEREROCHII_VALIDATOR_H

#include "Repo.h"
#include "Rochie.h"
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class ValidatorException: public exception {
private:
    string message;
public:
    ValidatorException(string msg): message{msg} {};

};

class Validator {
private:
    vector<string> errorMsg;
public:
    void validare_rochie(Rochie& r);
    string getErrorMsg() {
        string fullMsg = "";
        for (string e:errorMsg) {
            fullMsg += e + '\n';
        }
        return fullMsg;
    }
};


#endif //INCHIRIEREROCHII_VALIDATOR_H
