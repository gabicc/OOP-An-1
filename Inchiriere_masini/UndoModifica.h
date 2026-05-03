//
// Created by gabi on 4/27/26.
//

#ifndef INCHIRIERE_MASINI_UNDOMODIFICA_H
#define INCHIRIERE_MASINI_UNDOMODIFICA_H
#include "Undo.h"

#include "Masina.h"
#include <vector>
#include <string>

class UndoModifica: public ActiuneUndo {
private:
    string nr_inmatric_nou;
    Masina masina_modificata;
public:
    UndoModifica(vector<Masina> current_state, Masina masina_modificata, string nr_inmatric_nou);
    vector<Masina> doUndo();

    virtual ~UndoModifica(){};

};



#endif //INCHIRIERE_MASINI_UNDOMODIFICA_H
