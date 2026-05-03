//
// Created by gabi on 4/27/26.
//

#include "UndoSterge.h"

UndoSterge::UndoSterge(vector<Masina> current_state, Masina masina_stearsa): ActiuneUndo(current_state), masina_stearsa{masina_stearsa} {
}

vector<Masina> UndoSterge::doUndo() {
    vector<Masina> new_state = current_state;
    new_state.push_back(masina_stearsa);
    return new_state;
}
