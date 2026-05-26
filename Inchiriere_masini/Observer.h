//
// Created by gabi on 5/25/26.
//

#ifndef INCHIRIERE_MASINI_NOTIFIABLE_H
#define INCHIRIERE_MASINI_NOTIFIABLE_H

#include <vector>
#include "Masina.h"

using namespace std;

class Observer {

public:
    virtual ~Observer() {};
    virtual void notify(const vector<Masina> &masini) = 0;
};


#endif //INCHIRIERE_MASINI_NOTIFIABLE_H
