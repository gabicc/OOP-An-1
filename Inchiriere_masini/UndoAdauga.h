//
// Created by gabi on 4/27/26.
//

#ifndef INCHIRIERE_MASINI_UNDOADAUGA_H
#define INCHIRIERE_MASINI_UNDOADAUGA_H
#include "Undo.h"

#include "Masina.h"
#include <vector>


class UndoAdauga: public ActiuneUndo {

public:
    UndoAdauga(vector<Masina> current_state):ActiuneUndo(current_state){};
    vector<Masina> doUndo();

    virtual ~UndoAdauga(){};
};



#endif //INCHIRIERE_MASINI_UNDOADAUGA_H
