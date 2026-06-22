//
// Created by gabi on 6/20/26.
//

#include "Validator.h"

#include <vector>

void Validator::validateProdus(Produs p) {
    // pre: p - Produs
    // post: daca id e negativ, nume e vid sau pret nu e intre 1 si 100, se arunca exceptie
    vector<string> errors;
    if (p.getId() < 0)
        errors.push_back("Id-ul nu poate fi vid");
    if (p.getNume() == "")
        errors.push_back("Numele nu poate fi vid");
    if (p.getPret() < 1.0 || p.getPret() > 100.0)
        errors.push_back("Pretul trebuie sa fie intre 1.0 si 100.0");
    if (errors.size() > 0) {
        string fullMsg = "";
        for (string e: errors)
            fullMsg += e + '\n';
        throw ValidatorException(fullMsg);
    }
}
