//
// Created by gabi on 5/18/26.
//

#ifndef PROCESORSIPLACADEBAZA_REPO_H
#define PROCESORSIPLACADEBAZA_REPO_H

#include "PlacaDeBaza.h"
#include "Procesor.h"
#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class RepoException: public exception {
private:
    string errorMsg;
public:
    RepoException(string errorMessage): errorMsg{errorMessage} {}
    const char* what() const noexcept override {
        return errorMsg.c_str();
    }
};

class Repo {
private:
    vector<Procesor> procesoare;
    vector<PlacaDeBaza> placiBaza;
    string filenameProcesor, filenamePlaci;
    void loadFromFile(string filenameProcesor, string filenamePlaci) {
        ifstream fin(filenameProcesor);
        if (!fin.is_open())
            throw RepoException("Fisierul Procesor nu a putut fi deschis");
        string line;
        while (!fin.eof()) {
            getline(fin, line);
            if (line.empty())
                continue;
            stringstream sStream(line);
            string nume, nrThrd, soclu, pret;

            getline(sStream, nume, ',');
            getline(sStream, nrThrd, ',');
            getline(sStream, soclu, ',');
            getline(sStream, pret, ',');

            Procesor p(nume, stoi(nrThrd), stoi(soclu), stod(pret));
            procesoare.push_back(p);
        }
        ifstream fin2(filenamePlaci);
        if (!fin2.is_open())
            throw RepoException("Fisierul Placa nu a putut fi deschis");

        while (!fin2.eof()) {
            getline(fin2, line);
            if (line.empty())
                continue;
            stringstream sStream(line);
            string nume, soclu, pret;

            getline(sStream, nume, ',');
            getline(sStream, soclu, ',');
            getline(sStream, pret, ',');

            PlacaDeBaza p(nume, stoi(soclu), stod(pret));
            placiBaza.push_back(p);
        }
    }
public:
    Repo(string filenameProcesor, string filenamePlaca): filenameProcesor{filenameProcesor}, filenamePlaci{filenamePlaca} {
        loadFromFile(filenameProcesor, filenamePlaci);
    }
    ~Repo() {

    }
    void addPlaca(PlacaDeBaza& p);
    vector<PlacaDeBaza> filtrarePlaciSoclu(int soclu);
    double pretTotal(double pretProcesor, double pretPlaca);
    vector<Procesor> get_all_procesor_repo() {
        return this->procesoare;
    }
    vector<PlacaDeBaza> get_all_placi_repo() {
        return this->placiBaza;
    }
    void operator=(const Repo& other) {
        this->procesoare = other.procesoare;
        this->placiBaza = other.placiBaza;
    }
};


#endif //PROCESORSIPLACADEBAZA_REPO_H
