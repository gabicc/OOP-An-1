//
// Created by gabi on 5/18/26.
//

#include "Repo.h"

void Repo::addPlaca(PlacaDeBaza& p) {
    for (auto& placa: placiBaza) {
        if (placa.getNumePlaca() == p.getNumePlaca())
            throw RepoException("Placa exista deja");
    }
    placiBaza.push_back(p);
}
vector<PlacaDeBaza> Repo::filtrarePlaciSoclu(int soclu) {
    // vector<PlacaDeBaza> placi;
    // for (int i = 0; i < placiBaza.size(); i++)
    //     placi.push_back(placiBaza[i]);
    // for (int i = 0; i < placi.size(); i++) {
    //     if (placiBaza[i].getSocluPlaca() != soclu) {
    //         for (int j = i + 1; j < placi.size(); j++) {
    //             placi[j - 1] = placi[j];
    //         }
    //     }
    // }
    // return placi;
    vector<PlacaDeBaza> placi_noi;
    for (auto& placa: placiBaza) {
        if (placa.getSocluPlaca() == soclu)
            placi_noi.push_back(placa);
    }
    return placi_noi;
}
double Repo::pretTotal(double pretProcesor, double pretPlaca) {
    return pretProcesor + pretPlaca;
}