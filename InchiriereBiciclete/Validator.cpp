//
// Created by gabi on 5/17/26.
//

#include "Validator.h"

string toUppper(const string& s) {
    string rez;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            rez.push_back(s[i] - 32);
        else
            rez.push_back(s[i]);
    }
    return rez;
}

void Validator::validate(Bicicleta& b) {
    if (b.getCod() < 0)
        errors.push_back("Codul nu poate fi negativ");
    if (b.getDenumire() == "")
        errors.push_back("Denumirea nu poate fi vida");
    string marimeUpper = toUppper(b.getMarime());
    if (marimeUpper != "S" && marimeUpper != "M" &&
        marimeUpper != "L" && marimeUpper != "XS" &&
        marimeUpper != "XL")
        errors.push_back("Marimea trebuie sa fie XS, S, M, L sau XL");
    if (b.getPret() < 0)
        errors.push_back("Pretul nu poate fi negativ");
    if (errors.size() > 0) {
        string fullMsg;
        for (string& e: errors) {
            fullMsg += e + '\n';
        }
        throw ValidatorException(fullMsg);
    }
}