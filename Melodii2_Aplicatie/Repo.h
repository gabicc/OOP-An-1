//
// Created by gabi on 6/19/26.
//

#ifndef MELODII2_APLICATIE_REPO_H
#define MELODII2_APLICATIE_REPO_H

#include <iostream>
#include <string.h>
#include <vector>
#include "Melodie.h"
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
    string filename;
    vector<Melodie> melodii;
    void loadFromFile(string filename) {
        // pre: fisierul exista
        // post: vectorul melodii este populat cu melodiile din fisier
        ifstream fin(filename);
        if (!fin.is_open()) {
            throw RepoException("Fisierul nu se poate deschide pt LOAD");
        }
        string line;
        while (!fin.eof()) {
            getline(fin, line);
            if (line.empty())
                continue;
            string id, titlu, artist, gen;
            stringstream sStream(line);

            getline(sStream, id, ',');
            getline(sStream, titlu, ',');
            getline(sStream, artist, ',');
            getline(sStream, gen, ',');

            Melodie m(stoi(id), titlu, artist, gen);
            melodii.push_back(m);
        }
    }
public:
    Repo(string filename): filename{filename} {
        // pre: fisierul exista
        loadFromFile(filename);
    }
    vector<Melodie> get_all_repo() {
        // pre:
        // post: returneaza lista de melodii
        return melodii;
    }
    void addMelodie(Melodie m) {
        // pre: m e de tip melodie
        // post: daca m nu exista in lista, o adaugam
        int gasit = 0;
        for (Melodie& melodie: melodii) {
            if (m.getId() == melodie.getId()) {
                gasit = 1;
            }
        }
        if (gasit == 0) {
            melodii.push_back(m);
        }
        else {
            throw RepoException("Melodia exista deja");
        }
    }
    void removeMelodie(int id) {
        // pre: id e de tip int
        // post: daca id e in lista, eliminam melodia cu id-ul acela, altfel aruncam exceptie
        for (int i = 0; i < melodii.size(); i++) {
            if (melodii[i].getId() == id) {
                for (int j = i + 1; j < melodii.size(); j++) {
                    melodii[j - 1] = melodii[j];
                }
                melodii.pop_back();
                return;
            }
        }
    }
    void saveToFile() {
        // pre: fiserul exista
        // post: fisierul este suprascris cu melodiile din vector
        ofstream fout(filename);
        if (!fout.is_open()) {
            throw RepoException("Fisierul nu se poate deschide pt SAVE");
        }
        for (Melodie& m: melodii) {
            fout << m.getId() << "," << m.getTitlu() << "," << m.getArtist() << "," << m.getGen() << '\n';
        }
    }
};


#endif //MELODII2_APLICATIE_REPO_H
