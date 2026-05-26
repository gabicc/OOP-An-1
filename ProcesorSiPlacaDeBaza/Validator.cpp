//
// Created by gabi on 5/18/26.
//

#include "Validator.h"

void Validator::validate_placa(PlacaDeBaza &p) {
    if (p.getNumePlaca() == "")
        errors.push_back("Numele nu poate fi vid");
    if (p.getSocluPlaca() <= 0)
        errors.push_back("Soclul nu poate fi negativ sau egal cu 0");
    if (p.getPretPlaca() < 0)
        errors.push_back("Pretul nu poate fi negativ");

    if (errors.size() > 0) {
        string fullMsg;
        for (string& e: errors) {
            fullMsg += e + '\n';
        }
        throw ValidatorException(fullMsg);
    }
}
