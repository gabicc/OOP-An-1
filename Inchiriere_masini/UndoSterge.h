//
// Created by gabi on 4/27/26.
//

#ifndef INCHIRIERE_MASINI_UNDOSTERGE_H
#define INCHIRIERE_MASINI_UNDOSTERGE_H
#include "Undo.h"

#include "Masina.h"
#include <vector>

class UndoSterge: public ActiuneUndo {
private:
    Masina masina_stearsa;
public:
    UndoSterge(vector<Masina> current_state, Masina masina_stearsa);
    vector<Masina> doUndo();
    virtual ~UndoSterge(){};
};



#endif //INCHIRIERE_MASINI_UNDOSTERGE_H
