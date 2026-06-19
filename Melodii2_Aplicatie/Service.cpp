//
// Created by gabi on 6/19/26.
//

#include "Service.h"

void Service::addMelodie_srv(string titlu, string artist, string gen) {
    // pre: titlu, artist, gen - stirng
    // post: generam id pentru melodie si adaugam in lista
    vector<Melodie> melodii = repo.get_all_repo();
    int max_id = 0;
    if (melodii.size() > 0)
        max_id = melodii[0].getId();
    for (Melodie& m: melodii) {
        if (m.getId() > max_id)
            max_id = m.getId();
    }
    int id_new = max_id + 1;
    Melodie m(id_new, titlu, artist, gen);
    val.validateMelodie(m);
    repo.addMelodie(m);
}
void Service::removeMelodie_srv(int id) {
    // pre: id - int
    // post: stergem melodia cu acel id daca exista in lista
    repo.removeMelodie(id);
}