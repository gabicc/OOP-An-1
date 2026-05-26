//
// Created by gabi on 5/19/26.
//

#ifndef SIMULAREMOBILA_REPO_H
#define SIMULAREMOBILA_REPO_H
#include <exception>
#include <iostream>
#include <string.h>
#include <vector>
#include "Mobila.h"
#include <fstream>
#include <sstream>
#include <bits/atomic_base.h>

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
    vector<Mobila> mobile;
    string filename;
    void loadFromFile(string filename) {
        ifstream fin(filename);
        if (!fin.is_open()) {
            throw RepoException("Could not open file");
        }
        string line;
        while (!fin.eof()) {
            getline(fin, line);
            if (line.empty())
                continue;;
            stringstream sStream(line);
            string id, type, nrPieces, assemblyTime;
            getline(sStream, id, ',');
            getline(sStream, type, ',');
            getline(sStream, nrPieces, ',');
            getline(sStream, assemblyTime, ',');
            Mobila m(stoi(id), type, stoi(nrPieces), stoi(assemblyTime));
            mobile.push_back(m);
        }
        fin.close();
    }
public:
    Repo(string filename): filename{filename} {
        loadFromFile(filename);
    }
    ~Repo() {

    }
    void addMobila(Mobila m);
    vector<Mobila> filtrareType(string type);
    vector<Mobila> sortareNrPieces();
    vector<Mobila> sortareAssemblyTime();
    vector<Mobila> getAll_repo() {
        return this->mobile;
    }
};


#endif //SIMULAREMOBILA_REPO_H
