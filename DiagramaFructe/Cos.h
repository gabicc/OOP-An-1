//
// Created by gabi on 6/21/26.
//

#ifndef DIAGRAMAFRUCTE_COS_H
#define DIAGRAMAFRUCTE_COS_H

#include <vector>

using namespace std;

#include "Fruct.h"

class Cos {
private:
    vector<Fruct*> fructe;
public:
    // Cos() {};
    virtual ~Cos() {
        // for (Fruct* f: fructe) {
        //     delete f;
        // }
    }
    void add(Fruct* fruct) {
        fructe.push_back(fruct);
    }
    vector<Fruct*> getAll(bool cuSambure) {
        vector<Fruct*> rez;
        for (Fruct* f: fructe) {
            if (f->eCuSambure() == cuSambure) {
                rez.push_back(f);
            }
        }
        return rez;
    }
};


#endif //DIAGRAMAFRUCTE_COS_H
