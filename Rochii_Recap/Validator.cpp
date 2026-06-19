//
// Created by gabi on 6/13/26.
//

#include "Validator.h"

#include "Rochie.h"

void Validator::validateRochie(Rochie& r) {
    if (r.getCod() < 0) {
        errorMsg.push_back("Codul nu poate fi negativ");
    }
    if (r.getDenumire() == "") {
        errorMsg.push_back("Denumirea nu poate fi vida");
    }
    if (r.getMarime() < 0) {
        errorMsg.push_back("Marimea nu poate fi negativa");
    }
    if (r.getPret() < 0) {
        errorMsg.push_back("Pretul nu poate fi negativ");
    }
    if (errorMsg.size() > 0) {
        string fullMsg = "";
        for (string& e: errorMsg) {
            fullMsg += e + '\n';
        }
        throw ValidatorException(fullMsg);
    }
}
