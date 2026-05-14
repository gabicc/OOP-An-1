//
// Created by gabi on 5/12/26.
//

#include "Validator.h"

void Validator::validare_rochie(Rochie &r) {
    if (r.get_cod() < 0) {
        errorMsg.push_back("Codul nu poate fi negativ");
    }
    if (r.get_denumire().size() == 0) {
        errorMsg.push_back("Denumirea nu poate fi vida");
    }
    if (r.get_marime() <= 0) {
        errorMsg.push_back("Marimea nu poate fi negativa sau egala cu 0");
    }
    if (r.get_pret() < 0) {
        errorMsg.push_back("Pretul nu poate fi negativ");
    }

    if (r.get_disponibil() != 0 && r.get_disponibil() != 1) {
        errorMsg.push_back("Disponibilitatea trebuie sa fie 0 sau 1");
    }

    if (errorMsg.size() > 0) {
        string fullMsg = "";
        for (const string& e: errorMsg) {
            fullMsg += e + '\n';
        }
     throw ValidatorException(fullMsg);
    }
}
