//
// Created by gabi on 6/22/26.
//

#ifndef STUDENTIAPLICATIE_REPO_H
#define STUDENTIAPLICATIE_REPO_H

#include <iostream>
#include <string>
#include "Student.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <exception>

using namespace std;

class RepoException: public exception {
private:
    string errorMsg;
public:
    RepoException(string errorMessage): errorMsg{errorMessage} {};
    // pre: errorMessage - string
    // post: returneaza mesajul de eroare
    const char* what() const noexcept override {
        // post: returneaza mesajul de eroare
        return errorMsg.c_str();
    }
};

class Repo {
private:
    vector<Student> studenti;
    vector<vector<Student>> undos;
    vector<vector<Student>> redos;
    string filename;
    void loadFromFile() {
        // post: citesc din fisier si adaug in lista de studenti fiecare student citit
        ifstream fin(filename);
        if (!fin.is_open())
            throw RepoException("Fisierul nu se poate deschide pentru LOAD");
        string line;
        while (!fin.eof()) {
            getline(fin, line);

            stringstream sStream(line);
            string id, nume, varsta, facultate;
            getline(sStream, id, ',');
            getline(sStream, nume, ',');
            getline(sStream, varsta, ',');
            getline(sStream, facultate, ',');
            Student s(stoi(id), nume, stoi(varsta), facultate);
            studenti.push_back(s);
        }
    }
public:
    Repo(string filename): filename{filename} {
        // pre: filename - string
        // post: citesc din fisierul cu numele filename
        loadFromFile();
    };
    vector<Student> get_all_repo() {
        // post: returnez lista de studenti
        return studenti;
    }
    void removeStudent(int nrmatricol) {
        // pre: nrmatricol - int
        // post: sterg studentul cu nr matricol mentionat
        undos.push_back(studenti);
        for (int i = 0; i < studenti.size(); i++) {
            if (studenti[i].getNrMatricol() == nrmatricol) {
                for (int j = i + 1; j < studenti.size(); j++) {
                    studenti[j - 1] = studenti[j];
                }
                studenti.pop_back();
            }
        }
    }
    void saveToFile(vector<Student> students) {
        // pre: students - lista de studenti
        // post: salvez in fisier lista de studenti
        ofstream fout(filename);
        if (!fout.is_open())
            throw RepoException("Fisierul nu se poate deschide pentru SAVE");
        for (Student& s: students) {
            fout << s.getNrMatricol() << "," << s.getNume() << "," << s.getVarsta() << "," << s.getFacultate() << '\n';
        }
    }
    // void imbatranire_repo(vector<Student> studenti) {
    //     for (Student& s: studenti) {
    //         s.imbatranire();
    //     }
    // }
    void overscrie(vector<Student> studs) {
        // pre: studs - vector de studenti
        // post: inlocuieste vectorul de studenti din privat cu cel dat ca paramentru
        for (int i = 0; i < studs.size(); i++) {
            studenti[i] = studs[i];
        }
    }
    void intinerire_repo() {
        // post: scad varsta la fiecare student cu un an
        undos.push_back(studenti);
        for (Student& s: studenti)
            s.intinerire();
    }
    void imbatranire_repo() {
        // post: cresc varsta la fiecare student cu un an
        undos.push_back(studenti);
        for (Student& s: studenti) {
            s.imbatranire();
        }
    }
    void undo() {
        // post: lista de studenti e inlocuita cu lista anterioara de studenti
        redos.push_back(studenti);
        vector<Student> rez = undos[undos.size() - 1];
        //studenti = rez;
        int i;
        for (i = 0; i < studenti.size(); i++) {
            studenti[i] = rez[i];
        }
        while (i < rez.size()) {
            studenti.push_back(rez[i]);
            i++;
        }
    }
    void redo() {
        // post: lista de stundenti e inlocuita cu lista de studenti inainte de undo
        vector<Student> rez = redos[redos.size() - 1];
        int i;
        for (i = 0; i < rez.size(); i++) {
            studenti[i] = rez[i];
        }
        int dif = studenti.size() - rez.size();
        i = 0;
        while (i < dif) {
            studenti.pop_back();
            i++;
        }
    }
};


#endif //STUDENTIAPLICATIE_REPO_H
