//
// Created by gabi on 6/22/26.
//

#include "Validator.h"

void Validator::validateStudent(Student s) {
    // pre: s - Student
    // post: daca nrmatriculare e negativ, numele e vid, varsta e negativa sau facultatea nu e dintre cele precizate in cerinta, se arunca exceptie
    vector<string> errors;
    if (s.getNrMatricol() < 0)
        errors.push_back("Nr matricol nu poate fi negativ");
    if (s.getNume() == "")
        errors.push_back("Numele nu poate fi vid");
    if (s.getVarsta() < 0)
        errors.push_back("Varsta nu poate fi negativa");
    if (s.getFacultate() != "mate" && s.getFacultate() != "info" && s.getFacultate() != "mate-info" && s.getFacultate() != "ai")
        errors.push_back("Facultatea trebuie sa fie dintre cele specificate");
    if (errors.size() > 0) {
        string fullMsg = "";
        for (string& e: errors) {
            fullMsg += e + '\n';
        }
        throw ValidatorException(fullMsg);
    }
}