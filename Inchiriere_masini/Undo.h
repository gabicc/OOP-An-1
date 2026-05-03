//
// Created by gabi on 4/26/26.
//

#ifndef INCHIRIERE_MASINI_UNDO_H
#define INCHIRIERE_MASINI_UNDO_H

#include "Masina.h"
#include <vector>


class ActiuneUndo {
protected:
    vector<Masina> current_state;
public:
    ActiuneUndo(vector<Masina> current_state): current_state{current_state}{};
    virtual vector<Masina> doUndo() = 0;
    virtual ~ActiuneUndo(){};

};



#endif //INCHIRIERE_MASINI_UNDO_H
