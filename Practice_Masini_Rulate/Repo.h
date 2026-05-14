//
// Created by gabi on 5/14/26.
//

#ifndef PRACTICE_MASINI_RULATE_REPO_H
#define PRACTICE_MASINI_RULATE_REPO_H

#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "Masina.h"
#include <algorithm>

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
    vector<Masina> masini;
    string filename;
    void loadFromFile() {
        ifstream fin("Masini.txt");
        if (!fin.is_open()) {
            throw RepoException("Could not open file");
        }
        while (!fin.eof()) {
            string line;
            getline(fin, line); // acum am linia
            if (line.empty())
                continue;
            stringstream sStream(line);
            string nrMatricol, model, culoare;
            string km;

            getline(sStream, nrMatricol, ',');
            getline(sStream, model, ',');
            getline(sStream, culoare, ',');
            getline(sStream, km, ',');

            Masina m((nrMatricol.data()), (model.data()), (culoare.data()), stoi(km));
            this->masini.push_back(m);
        }
    }
public:
    Repo(string filename): filename{filename} {
        loadFromFile();
    };
    void addMasina(Masina m);
    void removeMasina(char* nrMatricol);
    void updateMasina(char* nrMatricol, Masina m);
    vector<Masina> get_all_repo() const {
        return this->masini;
    }
    Masina& find_by_nrMatricol(const char* nrMatricol) {
        auto result = find_if(masini.begin(), masini.end(), [nrMatricol](const Masina& current) {
            return current.getNrMatricol() == nrMatricol;
        });
        if (result == masini.end()) {
            throw RepoException("Masina not found");
        }
        return *result;
    }
};


#endif //PRACTICE_MASINI_RULATE_REPO_H
