//
// Created by gabi on 6/21/26.
//

#ifndef TASKSAPLICATIE_REPO_H
#define TASKSAPLICATIE_REPO_H
#include <exception>

#include <iostream>
#include <string.h>
#include <vector>
#include "Task.h"
#include <fstream>
#include <sstream>

using namespace std;

class RepoException: public exception {
private:
    string errorMsg;
public:
    RepoException(string errorMessage): errorMsg{errorMessage} {};
    const char* what() const noexcept override {
        return errorMsg.c_str();
    }
};

class Repo {
private:
    vector<Task> taskuri;
    string filename;
    void loadFromFile() {
        // pre:
        // post: deschidem fisierul si adaugam intr-o lista de Taskuri toate taskurile din fisier
        ifstream fin(filename);
        if (!fin.is_open())
            throw RepoException("Fisierul nu se poate deschide pt LOAD");
        string line;
        while (!fin.eof()) {
            getline(fin, line);

            stringstream sStream(line);
            string id, descriere, stare;
            getline(sStream, id, ',');
            getline(sStream, descriere, ',');
            vector<string> programatori_list;
            string nume;
            while (getline(sStream, nume, ',')) {
                programatori_list.push_back(nume);
            }
            stare = programatori_list[programatori_list.size() - 1];
            programatori_list.pop_back();
            Task t(stoi(id), descriere, programatori_list, stare);
            taskuri.push_back(t);
        }
    }
public:
    Repo(string filename): filename{filename} {
        // pre: filename - string
        // post: am luat taskurile din fisier
        loadFromFile();
    }
    vector<Task> get_all_repo() {
        // post: returnam lista de taskuri
        return taskuri;
    }
    void addTask(Task t) {
        //pre:  t - Task
        // post: adaugam in lista de taskuri taskul t dupa ce verificam ca id-ul taskului nu e deja in lista
        for (Task& task: taskuri) {
            if (task.getId() == t.getId())
                throw RepoException("Taskul exista deja");
        }
        taskuri.push_back(t);
    }
    vector<Task> find_programator(string nume_programator) {
        // pre: nume_programator - string, numele programatorului cautat
        // post: returneaza lista de taskuri pt care lucreaza programatorul cu numele dat
        vector<Task> rez;
        for (Task& t: taskuri) {
            vector<string> programatori = t.getProgramatori();
            for (string& name: programatori) {
                if (name == nume_programator)
                    rez.push_back(t);
            }
        }
        return rez;
    }
    void modifyStare(Task t, string stare_noua) {
        // pre: t - Task, stare_noua, stare_noua - string
        // post: schimbam la  taskul t sa fie starea stare_noua
        Task t2(t.getId(), t.getDescriere(), t.getProgramatori(), stare_noua);
        for (Task& task: taskuri) {
            if (task.getId() == t.getId()) {
                task = t2;
            }
        }
    }

    void saveToFile() {
        ofstream fout(filename);
        if (!fout.is_open())
            throw RepoException("Fisierul nu se deschiude pt SAVE");
        for (Task& t: taskuri) {
            fout << t.getId() << "," << t.getDescriere() << ",";
            for (string e: t.getProgramatori()) {
                fout << e << ",";
            }
            fout << t.getStare() << '\n';
        }
    }
};


#endif //TASKSAPLICATIE_REPO_H
