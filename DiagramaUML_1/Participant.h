//
// Created by gabi on 6/20/26.
//

#ifndef DIAGRAMAUML_1_PARTICIPANT_H
#define DIAGRAMAUML_1_PARTICIPANT_H


class Participant {
public:
    virtual ~Participant() {

    };
    virtual void tipareste() = 0;
    virtual bool eVoluntar() {
        return true;
    }
};


#endif //DIAGRAMAUML_1_PARTICIPANT_H
