//
// Created by gabi on 5/12/26.
//

#include "Repo.h"
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


Repo::~Repo() {

}

void Repo::addRochie(Rochie r) {
    for (auto& rochie: rochii) {
        if (rochie.get_cod() == r.get_cod()) {
            throw RepoException("Rochia exista deja");
        }
    }
    rochii.push_back(r);
}

void Repo::removeRochie(int cod) {
    auto it = find_if(rochii.begin(), rochii.end(), [cod](Rochie& r) {
        return r.get_cod() == cod;
    });
    if (it == rochii.end()) {
        throw RepoException("Rochia nu exista");
    }
    rochii.erase(it);
}

void Repo::updateRochie(int cod, Rochie r_nou) {
    for (auto& r: rochii) {
        if (r.get_cod() == cod) {
            r = r_nou;
            return;
        }
    }
    throw RepoException("Rochia nu exista");
}

void Repo::afisRochii() {
    for (auto& r: rochii) {
        cout << r.get_cod() << " " << r.get_denumire() << " " << r.get_marime() << " " << r.get_pret() << " " << r.get_disponibil() << '\n';
    }
}