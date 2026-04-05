//
// Created by gabi on 4/5/26.
//

#include "Validator.h"
#include <vector>
#include <string>
#include <iostream>
#include <ranges>

void Validator::validate_masina(const Masina& m) {
    vector<string> errors;

    if (m.get_nr_inmatriculare().size() < 5) {
        errors.push_back("Nr inmatriculare trebuie sa contica cel putin 5 caractere");
    }
    if (m.get_producator().empty()) {
        errors.push_back("Producator nu poate fi vid");
    }
    if (m.get_model().empty()) {
        errors.push_back("Model nu poate fi vid");
    }
    if (m.get_tip().empty()) {
        errors.push_back("Tip nu poate fi vid");
    }
    if (!errors.empty()) {
        string result;
        //throw ValidationException(join(errors, "; "));
        for (string error : errors) {
            result += error + "\n";
        }
        throw ValidationException(result);
    }
}