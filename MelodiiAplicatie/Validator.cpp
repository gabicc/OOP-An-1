//
// Created by gabi on 6/18/26.
//

#include "Validator.h"

void Validator::validateMelodie(Melodie m) {
    vector<string> errors;
    // id trebuie sa fie pozitiv, id trebuie sa nu se repete, titlul si artistul nevide si rankul sa fie intre 0 si 10
    if (m.getId() < 0) {
        errors.push_back("Id nu poate fi negativ");
    }
    vector<Melodie> melodii = repo.get_all_repo();
    /*for (Melodie& melodie: melodii) {
        if (m.getId() == melodie.getId()) {
            throw ValidatorException("Id-ul trebuie sa fie unic");
        }
    }
    */
    if (m.getTitlu() == "") {
        errors.push_back("Titlul nu poate fi vid");
    }
    if (m.getArtist() == "")
        errors.push_back("Artistul nu poate fi vid");
    if (m.getRank() < 0 || m.getRank() > 10)
        errors.push_back("Rankul trebuie sa fie intre 0 si 10");
    if (errors.size() > 0) {
        string fullMsg = "";
        for (string err: errors) {
            fullMsg += err + '\n';
        }
        throw ValidatorException(fullMsg);
    }
}