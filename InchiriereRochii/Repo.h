//
// Created by gabi on 5/12/26.
//

#ifndef INCHIRIEREROCHII_REPO_H
#define INCHIRIEREROCHII_REPO_H

#include "Rochie.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class RepoException:public exception {
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
    vector<Rochie> rochii;
    string filename;
    void loadFromFile(string filename) {
        ifstream fin(filename);
        if (!fin.is_open()) {
            throw RepoException("Could not open file");
        }
        string line;
        while (!fin.eof()) {
            string line;
            getline(fin, line);
            if (line.empty())
                continue;
            stringstream sStream(line);
            string cod, denumire, marime, pret, disponibil;

            getline(sStream, cod, ',');
            getline(sStream, denumire, ',');
            getline(sStream, marime, ',');
            getline(sStream, pret, ',');
            getline(sStream, disponibil, ',');

            if (disponibil == "False") {
                Rochie r(stoi(cod), denumire, stod(marime), stod(pret), false);
                addRochie(r);
            }
            else {
                Rochie r(stoi(cod), denumire, stod(marime), stod(pret), true);
                addRochie(r);
            }
        }
    }
public:
    Repo(string filename): filename{filename} {
        loadFromFile(filename);
    }
    ~Repo();
    void addRochie(Rochie r);
    void removeRochie(int cod);
    void updateRochie(int cod, Rochie r_nou);
    void afisRochii();
    vector<Rochie> get_all_repo() {
        return this->rochii;
    }
};


#endif //INCHIRIEREROCHII_REPO_H
