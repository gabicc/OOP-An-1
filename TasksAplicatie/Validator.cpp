//
// Created by gabi on 6/21/26.
//

#include "Validator.h"

void Validator::validateTask(Task t) {
    // pre: t - Task
    // post: verificam ca descirerea sa nu fie vida, nr de programatori sa fie intre 1 si 4 si starea sa fie
    // dintre cele mentionate
    // Daca cel putin una dintre astea nu se intampla, se arunca exceptie
    vector<string> errors;
    if (t.getDescriere() == "")
        errors.push_back("Descrierea nu poate fi vida");
    vector<string> programatori = t.getProgramatori();

    if (programatori.size() < 1 || programatori.size() > 4)
        errors.push_back("Numarul de programatori trebuie sa fie intre 1 si 4");

    if (t.getStare() != "open" && t.getStare() != "inprogress" && t.getStare() != "closed")
        errors.push_back("Stare trebuie sa fie dintre open, inprogress si closed");

    if (errors.size() > 0) {
        string fullMsg = "";
        for (string& e: errors) {
            fullMsg += e + '\n';
        }
        throw ValidatorException(fullMsg);
    }
}