//
// Created by gabi on 6/21/26.
//

#ifndef DIAGRAMAFRUCTE_FRUCT_H
#define DIAGRAMAFRUCTE_FRUCT_H


class Fruct {
public:
    virtual ~Fruct() {

    }
    virtual void tipareste() = 0;
    virtual bool eCuSambure() {
        return false;
    }
};


#endif //DIAGRAMAFRUCTE_FRUCT_H
