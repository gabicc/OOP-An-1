//
// Created by gabi on 5/17/26.
//

#ifndef INCHIRIEREBICICLETE_REPO_H
#define INCHIRIEREBICICLETE_REPO_H
#include <exception>

#include <string.h>
#include <iostream>
#include <vector>
#include "Bicicleta.h"
#include <fstream>
#include <sstream>

using namespace std;

class RepoException: public std::exception {
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
    vector<Bicicleta> biciclete;
    vector<Bicicleta> copieBiciclete;
    string filename;
    void loadFromFile(string filename) {
        ifstream fin(filename);
        if (!fin.is_open()) {
            throw RepoException("Nu s-a putut deschide fisierul");
        }
        string line;
        while (!fin.eof()) {
            getline(fin, line);
            if (line.empty())
                continue;
            stringstream sStream(line);
            string cod, denumire, marime, pret, disponibila;
            getline(sStream, cod, ',');
            getline(sStream, denumire, ',');
            getline(sStream, marime, ',');
            getline(sStream, pret, ',');
            getline(sStream, disponibila, ',');
            if (disponibila == "1") {
                Bicicleta b(stoi(cod), denumire, marime, stod(pret), 1);
                biciclete.push_back(b);
                copieBiciclete.push_back(b);
            }
            else {
                Bicicleta b(stoi(cod), denumire, marime, stod(pret), 0);
                biciclete.push_back(b);
                copieBiciclete.push_back(b);
            }
        }
    }
public:
    Repo(string filename): filename{filename} {
        loadFromFile(filename);
    }
    virtual ~Repo();
    vector<Bicicleta> get_all_repo() {
        return biciclete;
    }

    void inchiriereBicicleta(int cod);
    vector<Bicicleta> sortareMarime();
    vector<Bicicleta> sortarePret();
    vector<Bicicleta> nesortat();

    void operator=(const Repo& other) {
        this->biciclete = other.biciclete;
        this->filename = other.filename;
    }

};


#endif //INCHIRIEREBICICLETE_REPO_H
