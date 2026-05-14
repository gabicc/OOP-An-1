//
// Created by gabi on 5/12/26.
//

#include "Service.h"
#include <fstream>

using namespace std;

Service::Service() {

}

Service::~Service() {

}

void Service::addRochie_srv(Rochie r) {
    validator.validare_rochie(r);
    this->repo.addRochie(r);
}

void Service::removeRochie_srv(int cod) {
    this->repo.removeRochie(cod);
}

void Service::updateRochie_srv(int cod, Rochie r_nou) {
    validator.validare_rochie(r_nou);
    this->repo.updateRochie(cod, r_nou);
}

void Service::afisRochii_srv() {
    this->repo.afisRochii();
}

void Service::load_from_file(string filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Nu s-a putut deschide fisierul\n";
        return;
    }
    string line;
    while (getline(fin, line)) {
        int cod = 0;
        string denumire;
        double marime;
        double pret;
        bool disponibil;

        int i = 0;
        while (i < line.size() && line[i] != ',') {
            cod = cod * 10 + line[i] - '0';
            i++;
        }
        i++;
        while (i < line.size() && line[i] != ',') {
            denumire += line[i];
            i++;
        }
        i++;
        while (i < line.size() && line[i] != ',') {
            marime = marime * 10 + line[i] - '0';
            i++;
        }
        i++;
        while (i < line.size() && line[i] != ',') {
            pret = pret * 1- + line[i] - '0';
            i++;
        }
        i++;
        if (line[i] == '1' || line[i] == 'T')
            disponibil = true;
        else
            disponibil = false;
        Rochie r(cod, denumire, marime, pret, disponibil);
        try {
            addRochie_srv(r);
        }
        catch (ValidatorException& e) {
            cout << "Rochia de pe linia " << line << " nu a fost adaugata\n";
        }
    }
}
