//
// Created by gabi on 6/21/26.
//

#ifndef TASKSAPLICATIE_SERVICE_H
#define TASKSAPLICATIE_SERVICE_H

#include <exception>

#include <iostream>
#include <string.h>
#include <vector>
#include "Task.h"
#include <fstream>
#include <sstream>
#include "Repo.h"
#include "Validator.h"

using namespace std;

class Service {
private:
    Repo repo;
    Validator val;
public:
    Service(Repo repo, Validator val): repo{repo}, val{val} {};
    vector<Task> get_all_srv() {
        // post: returneaza lista de programatori
        vector<Task> taskuri = repo.get_all_repo();
        for (int i = 0; i < taskuri.size() - 1; i++) {
            for (int j = i + 1; j < taskuri.size(); j++) {
                if (taskuri[i].getStare() > taskuri[j].getStare()) {
                    Task aux = taskuri[i];
                    taskuri[i] = taskuri[j];
                    taskuri[j] = aux;
                }
            }
        }
        return taskuri;
    }
    void addTask_srv(int id, string descriere, vector<string> programatori, string stare) {
        // pre: id- int, descriere, stare - string, programatoriu - vector<string>
        // post: creem task cu id, desciere, programatoriu si stare dintre parametri, apoi validam si adaugam
        // in lista
        Task t(id, descriere, programatori, stare);
        try {
            val.validateTask(t);
            repo.addTask(t);
        }catch (RepoException& re) {
            throw RepoException(re.what());
        }
        catch (ValidatorException& ve) {
            throw ValidatorException(ve.what());
        }
    }
    vector<Task> findProgramator_srv(string nume_programator) {
        // pre: nume_programator
        // post: returneaza lista de taskuri pt care lucreaza programatorul cu numele dat
        return repo.find_programator(nume_programator);
    }
    void saveToFile_srv() {
        repo.saveToFile();
    }
    void modifyTask_srv(Task& t, string stare_noua) {
        repo.modifyStare(t, stare_noua);
    }
};


#endif //TASKSAPLICATIE_SERVICE_H
