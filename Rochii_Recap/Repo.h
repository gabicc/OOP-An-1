//
// Created by gabi on 6/13/26.
//

#ifndef ROCHII_RECAP_REPO_H
#define ROCHII_RECAP_REPO_H
#include <exception>
#include <string>
#include <vector>
#include "Rochie.h"
#include <fstream>
#include <sstream>
#include <bits/atomic_base.h>

using namespace std;

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
    vector<Rochie> rochii;
    string filename;
    void loadFromFile(string filename) {
        ifstream fin(filename);
        if (!fin.is_open())
            throw RepoException("Could not open file");
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
            if (disponibila == "false") {
                Rochie r(stoi(cod), denumire, stoi(marime), stod(pret), false);
                rochii.push_back(r);
            }
            else {
                Rochie r(stoi(cod), denumire, stoi(marime), stod(pret), true);
                rochii.push_back(r);
            }
        }
    }
public:
    Repo(string filename): filename{filename} {
        loadFromFile(filename);
    }
    virtual ~Repo() {

    };
    void addRochie(Rochie r);
    void removeRochie(int cod);
    bool findRochie(int cod);
    void updateRochie(Rochie r_nou);
    vector<Rochie> get_all_rochii_repo();
};
#include <semaphore.h>
int sem_init(sem_t *sem, int pshared, unsigned int value);



#endif //ROCHII_RECAP_REPO_H
