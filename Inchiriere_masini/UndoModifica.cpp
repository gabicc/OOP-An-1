//
// Created by gabi on 4/27/26.
//

#include "UndoModifica.h"

UndoModifica::UndoModifica(vector<Masina> current_state, Masina masina_modificata, string nr_inmatric_nou): ActiuneUndo(current_state),
masina_modificata{masina_modificata}, nr_inmatric_nou{nr_inmatric_nou} {
};

vector<Masina> UndoModifica::doUndo() {
    vector<Masina> new_current = current_state;
    for (auto it = new_current.begin(); it != new_current.end(); it++) {
        if (it -> get_nr_inmatriculare() == nr_inmatric_nou) {
            *it = masina_modificata;
            return new_current;
        }
    }
    new_current.push_back(masina_modificata);
    return new_current;
}