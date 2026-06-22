//
// Created by gabi on 6/20/26.
//

#ifndef PRODUSEAPLICATIE_REPO_H
#define PRODUSEAPLICATIE_REPO_H
#include <exception>

#include <iostream>
#include <string.h>
#include <vector>
#include "Produs.h"
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
    vector<Produs> produse;
    string filename;
    void loadFromFile(string filename) {
        // pre: filename - string
        // post: se adauga in lista de produse cele citite din fisier
        ifstream fin(filename);
        if (!fin.is_open())
            throw RepoException("Fisierul nu se poate deschide pt LOAD");
        string line;
        while (!fin.eof()) {
            getline(fin, line);
            if (line.empty())
                continue;
            stringstream sStream(line);
            string id, nume, tip, pret;
            getline(sStream, id, ',');
            getline(sStream, nume, ',');
            getline(sStream, tip, ',');
            getline(sStream, pret, ',');

            Produs p(stoi(id), nume, tip, stod(pret));
            produse.push_back(p);
        }
    }
public:
    Repo(string filename): filename{filename} {
        loadFromFile(filename);
    }
    void addProdus(Produs p) {
        // pre: p - Produs
        // post: daca id e unic, se adauga produsul in lista de proidyse
        int gasit = 0;
        for (Produs& produs: produse) {
            if (produs.getId() == p.getId())
                gasit = 1;
        }
        if (gasit == 0)
            produse.push_back(p);
        else {
            throw RepoException("Produsul exista deja");
        }
    }
    vector<Produs> get_all_repo() {
        // prost: se returneaza lista de produsse
        return produse;
    }
    void saveToFile() {
        ofstream fout(filename);
        if (!fout.is_open())
            throw RepoException("Fisierul nu se poate deschide pt SAVE");
        for (Produs& p: produse) {
            fout << p.getId() << "," << p.getNume() << "," << p.getTip() << "," << p.getPret() << '\n';
        }
    }
};


#endif //PRODUSEAPLICATIE_REPO_H
