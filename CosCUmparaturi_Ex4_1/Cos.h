//
// Created by gabi on 6/20/26.
//

#ifndef COSCUMPARATURI_EX4_1_COS_H
#define COSCUMPARATURI_EX4_1_COS_H

#include <vector>
#include <iostream>

using namespace std;

template <typename TElem>

class Cos {
private:
    vector<TElem> elemente;
public:
    Cos<TElem>& operator+(TElem right) {
        elemente.push_back(right);
        return *this;
    }
    Cos<TElem>& operator=(Cos<TElem>& other) {
        this->elemente = other.elemente;
        return *this;
    }
    Cos<TElem>& undo() {
        if (!elemente.empty()) {
            elemente.pop_back();
        }
        return *this;
    }
    void tipareste(ostream& out) {
        for (TElem& e: elemente) {
            out << e << " ";
        }
    }
};


#endif //COSCUMPARATURI_EX4_1_COS_H
