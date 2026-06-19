//
// Created by gabi on 6/13/26.
//

#include "Repo.h"
#include <algorithm>

void Repo::addRochie(Rochie r) {
    for (auto& rochie: rochii) {
        if (r.getCod() == rochie.getCod()) {
            throw RepoException("Rochia exista deja");
        }
    }
    rochii.push_back(r);
}
void Repo::removeRochie(int cod) {
    auto it = find_if(rochii.begin(), rochii.end(), [cod](Rochie& r) {
        return r.getCod() == cod;
    });
    if (it == rochii.end()) {
        throw RepoException("Rochia nu exista");
    }
    rochii.erase(it);
}
bool Repo::findRochie(int cod) {
    for (auto& r: rochii) {
        if (r.getCod() == cod)
            return true;
    }
    return false;
}
void Repo::updateRochie(Rochie r_nou) {
    for (auto& r: rochii) {
        if (r.getCod() == r_nou.getCod()) {
            r = r_nou;
            return;
        }
    }
}
vector<Rochie> Repo::get_all_rochii_repo() {
    return rochii;
}