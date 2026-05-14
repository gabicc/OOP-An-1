//
// Created by gabi on 5/14/26.
//

#include "Validator.h"

void Validator::validateMasina(Masina m) {
    if (m.getNrMatricol() == "") {
        errorMsg.push_back("Numar matricol nu poate fi vid");
    }
    if (m.getModel() == "") {
        errorMsg.push_back("Model nu poate fi vid");
    }
    if (m.getCuloare() == "") {
        errorMsg.push_back("Culoare nu poate fi vid");
    }
    if (m.getKm() < 0) {
        errorMsg.push_back("Kilometrii nu pot fi negativi");
    }
    if (errorMsg.size() > 0) {
        throw ValidatorException(this->getErrorMsg());
    }
}
