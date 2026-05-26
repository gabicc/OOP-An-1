//
// Created by gabi on 5/19/26.
//

#include "Validator.h"

void Validator::validateMobila(Mobila m) {
    if (m.getId() < 0) {
        errors.push_back("Id nu poate fi negativ");
    }
    if (m.getType() != "nightstand" && m.getType() != "bed" && m.getType() != "table" && m.getType() != "wardrobe")
        errors.push_back("Tipul trebuie sa fie nightstand, bed, table sau wardrobe");
    if (m.getNrPieces() < 0) {
        errors.push_back("Numarul de piese nu poate fi negativ");
    }
    if (m.getAssemblyTime() < 0) {
        errors.push_back("Assembly time nu poate fi negativ");
    }
    if (errors.size() > 0) {
        string fullMsg;
        for (auto& e: errors) {
            fullMsg += e + '\n';
        }
        throw ValidatorException(fullMsg);
    }
}