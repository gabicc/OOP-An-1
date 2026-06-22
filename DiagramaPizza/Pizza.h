//
// Created by gabi on 6/20/26.
//

#ifndef DIAGRAMAPIZZA_PIZZA_H
#define DIAGRAMAPIZZA_PIZZA_H

#include <iostream>

using namespace std;

class Pizza {
private:
    int pret;
public:
    Pizza(int price): pret{price} {};
    virtual ~Pizza() {

    };
    virtual string descriere() = 0;
    virtual int getPret() {
        return pret;
    }
};


#endif //DIAGRAMAPIZZA_PIZZA_H
