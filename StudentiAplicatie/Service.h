//
// Created by gabi on 6/22/26.
//

#ifndef STUDENTIAPLICATIE_SERVICE_H
#define STUDENTIAPLICATIE_SERVICE_H

#include <iostream>
#include <string>
#include "Student.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>
#include "Repo.h"
#include "Validator.h"

using namespace std;

class Service {
private:
    Repo repo;
    Validator val;
public:
    // clasa Service are un Repo si un Validator
    Service(Repo repo, Validator val): repo{repo}, val{val} {};
    vector<Student> get_all_srv() {
        // post: returneaza lista de studenti ordonata crescator dupa varsta
        vector<Student> list = repo.get_all_repo();

        for (int i = 0; i < list.size() - 1; i++) {
            for (int j = i + 1; j < list.size(); j++) {
                if (list[i].getVarsta() > list[j].getVarsta()) {
                    Student aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }

            }
        }
        return list;
    }
    void removeStudent_srv(int nrmatricol) {
        // pre: nrmatricol - int
        // post: sterge studentul cu nr matricol mentionat
        repo.removeStudent(nrmatricol);
    }
    void saveToFile_srv(vector<Student> studs) {
        // pre: studs - lista de studenti
        // post: salvez in fisier lista de studenti
        repo.saveToFile(studs);
    }
    void overscrie(vector<Student> students) {
        // pre: students - lista de studenti
        // post: inlocuiesc lista de studenti cu cea daca ca paramentru
        repo.overscrie(students);
    }
    void intinerire_srv() {
        // post: intineresc studentii
        repo.intinerire_repo();
    }
    void imbatranire_srv() {
        // post: imbatranesc studentii
        repo.imbatranire_repo();
    }
    void undo_srv() {
        // post: refac ultima operatie
        repo.undo();
    }
    void redo_srv() {
        // post: readuc vectorul de studenti la cel inainte de undo
        repo.redo();
    }
};


#endif //STUDENTIAPLICATIE_SERVICE_H
