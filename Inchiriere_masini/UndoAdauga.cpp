//
// Created by gabi on 4/27/26.
//

#include "UndoAdauga.h"

vector<Masina> UndoAdauga::doUndo() {
    current_state.pop_back();
    return current_state;
}