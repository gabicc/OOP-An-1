//
// Created by gabi on 5/17/26.
//

#include "Repo.h"

Repo::~Repo() {

}

void Repo::inchiriereBicicleta(int cod) {
    for (auto& b: biciclete) {
        if (b.getCod() == cod) {
            if (b.getDisponibila() == 1) {
                b = Bicicleta(b.getCod(), b.getDenumire(), b.getMarime(), b.getPret(), 0);
            }
            else {
                throw RepoException("Bicicleta nu e disponibila");
            }
        }
    }
}
vector<Bicicleta> Repo::sortareMarime() {
    for (int i = 0; i < biciclete.size() - 1; i++) {
        for (int j = i + 1; j < biciclete.size(); j++) {
            if (biciclete[i].getMarime() > biciclete[j].getMarime()) {
                Bicicleta aux = biciclete[i];
                biciclete[i] = biciclete[j];
                biciclete[j] = aux;
            }
        }
    }
    return biciclete;
}
vector<Bicicleta> Repo::sortarePret() {
    for (int i = 0; i < biciclete.size(); i++) {
        for (int j = i + 1; j < biciclete.size(); j++) {
            if (biciclete[i].getPret() > biciclete[j].getPret()) {
                Bicicleta aux = biciclete[i];
                biciclete[i] = biciclete[j];
                biciclete[j] = aux;
            }
        }
    }
    return biciclete;
}
vector<Bicicleta> Repo::nesortat() {
    for (int i = 0; i < copieBiciclete.size(); i++) {
        biciclete[i] = copieBiciclete[i];
    }
    return biciclete;
}
