//
// Created by gabi on 6/22/26.
//

#ifndef STUDENTIAPLICATIE_STUDENT_H
#define STUDENTIAPLICATIE_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int nrmatricol;
    string nume;
    int varsta;
    string facultate;
public:
    // un stundent are nrmatricol, nume, varsta, facultate
    Student(int nrmatricol, string nume, int varsta, string facultate): nrmatricol{nrmatricol}, nume{nume}, varsta{varsta}, facultate{facultate} {};
    virtual ~Student() {

    }
    int getNrMatricol() {
        // post: returneaza nr matricol
        return nrmatricol;
    }
    string getNume() {
        // post: returneaza numele
        return nume;
    }
    int getVarsta() {
        // post: returneaza varsta
        return varsta;
    }
    string getFacultate() {
        // post: retuneaza facultatea
        return facultate;
    }
    void imbatranire() {
        varsta += 1;
    }
    void intinerire() {
        varsta -= 1;
    }
    void operator=(Student& other) {
        // pre: other - Student&
        // post: asociaza un stundent cu un altul
        nrmatricol = other.nrmatricol;
        nume = other.nume;
        varsta = other.varsta;
        facultate = other.facultate;
    }
};


#endif //STUDENTIAPLICATIE_STUDENT_H
