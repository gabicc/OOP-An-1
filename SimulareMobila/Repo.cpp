//
// Created by gabi on 5/19/26.
//

#include "Repo.h"

void Repo::addMobila(Mobila m) {
    mobile.push_back(m);
}
vector<Mobila> Repo::filtrareType(string type) {
    vector<Mobila> filtered;
    for (auto& m: mobile) {
        if (m.getType() == type) {
            filtered.push_back(m);
        }
    }
    return filtered;
}

vector<Mobila> Repo::sortareNrPieces() {
    vector<Mobila> sorted;
    for (auto& m: mobile) {
        sorted.push_back(m);
    }
    for (int i = 0; i < sorted.size() - 1; i++) {
        for (int j = i + 1; j < sorted.size(); j++) {
            if (sorted[i].getNrPieces() > sorted[j].getNrPieces()) {
                Mobila aux = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = aux;
            }
        }
    }
    return sorted;
}
vector<Mobila> Repo::sortareAssemblyTime() {
    vector<Mobila> sorted;
    for (auto& m: mobile) {
        sorted.push_back(m);
    }
    for (int i = 0; i < sorted.size() - 1; i++) {
        for (int j = i + 1; j < sorted.size(); j++) {
            if (sorted[i].getAssemblyTime() > sorted[j].getAssemblyTime()) {
                Mobila aux = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = aux;
            }
        }
    }
    return sorted;
}