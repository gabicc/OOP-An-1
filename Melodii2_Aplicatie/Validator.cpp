//
// Created by gabi on 6/19/26.
//

#include "Validator.h"

void Validator::validateMelodie(Melodie m) {
    // pre: m de tip melodie
    // post: aruncam exceptie daca id e negativ, titlu, artist e vid sau daca gen nu e dintre pop folk rock sau disco
    vector<string> errors;
    if (m.getId() < 0) {
        errors.push_back("Id-ul nu poate fi negativ");
    }
    if (m.getTitlu() == "") {
        errors.push_back("Titlul nu poate fi vid");
    }
    if (m.getArtist() == "")
        errors.push_back("Artistul nu poate fi vid");
    if (m.getGen() != "pop" && m.getGen() != "rock" && m.getGen() != "folk" && m.getGen() != "disco") {
        errors.push_back("Genul trebuie sa fie pop, rock, folk sau disco");
    }
    if (errors.size() > 0) {
        string fullMsg = "";
        for (string e: errors) {
            fullMsg += e + '\n';
        }
        throw ValidatorException(fullMsg);
    }
}