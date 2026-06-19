//
// Created by gabi on 6/18/26.
//

#ifndef MELODIIAPLICATIE_REPO_H
#define MELODIIAPLICATIE_REPO_H
#include <exception>

#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream>

#include "Melodie.h"

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
    vector<Melodie> melodii;
    string filename;
    // citeste din fisier si adauga melodiile in vectorul melodii
    void loadFromFile(string filename) {
        ifstream fin(filename);
        if (!fin.is_open()) {
            throw RepoException("Fisierul nu se poate deschide");
        }
        string line;
        while (!fin.eof()) {
            getline(fin, line);
            if (line.empty())
                continue;
            string id, titlu, artist, rank;
            stringstream sStream(line);

            getline(sStream, id, ',');
            getline(sStream, titlu, ',');
            getline(sStream, artist, ',');
            getline(sStream, rank, ',');

            Melodie m(stoi(id), titlu, artist, stoi(rank));
            melodii.push_back(m);
        }

    }
public:
    Repo(string filename): filename{filename} {
        loadFromFile(filename);
    }
    virtual ~Repo() {

    };
    // returneaza lista de melodii sortata dupa rank
    vector<Melodie> get_all_repo() {
        vector<Melodie> melodiii = melodii;
        int len = melodiii.size();
        for (int i = 0; i < melodiii.size() - 1; i++) {
            for (int j = i + 1; j < melodiii.size(); j++) {
                if (melodiii[i].getRank() > melodiii[j].getRank()) {
                    Melodie aux = melodiii[i];
                    melodiii[i] = melodiii[j];
                    melodiii[j] = aux;
                }
            }
        }
        return melodiii;
    }
    // modifica o melodie dupa id; Ii poate modifica atat titlul cat si rankul
    void modifyMelodie(Melodie m) {
        for (int i = 0; i < melodii.size(); i++) {
            if (melodii[i].getId() == m.getId()) {
                if (melodii[i].getArtist() != m.getArtist()) {
                    throw RepoException("Nu se poate modifica artistul melodiei");
                }
                melodii[i] = m;
                saveToFile();
                return;
            }
        }
    }
    // sterge o melodie dupa id
    void removeMelodie(int id) {
        for (int i = 0; i < melodii.size(); i++){
            if (melodii[i].getId() == id) {
                melodii.erase(melodii.begin() + i);
                saveToFile();
                return;
            }
        }
    }
    void saveToFile() {
        ofstream fout(filename);
        if (!fout.is_open()) {
            throw RepoException("Fisierul nu se poate deschide");
        }
        for (auto& m: melodii) {
            fout << m.getId() << "," << m.getTitlu() << "," << m.getArtist() << "," << m.getRank() << '\n';
        }
        fout.close();
    }
};


#endif //MELODIIAPLICATIE_REPO_H
