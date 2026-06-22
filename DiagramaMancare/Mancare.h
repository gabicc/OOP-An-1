//
// Created by gabi on 6/21/26.
//

#ifndef DIAGRAMAMANCARE_MANCARE_H
#define DIAGRAMAMANCARE_MANCARE_H

#include <iostream>
#include <string.h>

using namespace std;

class Mancare {
private:
    int pret;
public:
    Mancare(int price): pret{price} {};
    virtual ~Mancare() {
        //cout << "Destructor mancare" << endl;
    };
    virtual string descriere() =0;
    virtual int getPret() {
        return pret;
    }
};


#endif //DIAGRAMAMANCARE_MANCARE_H
