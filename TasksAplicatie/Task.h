//
// Created by gabi on 6/21/26.
//

#ifndef TASKSAPLICATIE_TASK_H
#define TASKSAPLICATIE_TASK_H

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Task {
private:
    int id;
    string descriere;
    vector<string> programatori;
    string stare;// poate fi open, in progress, closed
public:
    Task(int id, string descriere, vector<string> programatori, string stare): id{id}, descriere{descriere},
    programatori{programatori}, stare{stare} {};
    int getId() {
        return id;
    }
    string getDescriere() {
        return descriere;
    }
    vector<string> getProgramatori() {
        return programatori;
    }
    string getStare() {
        return stare;
    }
    void operator=(Task& other) {
        // pre: other - Task
        // post: asociem un obiect de tip Task cu un altul
        id = other.id;
        descriere = other.descriere;
        programatori = other.programatori;
        stare = other.stare;
    }
};


#endif //TASKSAPLICATIE_TASK_H
