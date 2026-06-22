//
// Created by gabi on 6/21/26.
//

#ifndef CARNET_EX4_CARNET_H
#define CARNET_EX4_CARNET_H
#include <iostream>
#include <vector>
#include <map>
#include <exception>

using namespace std;

template <typename T> class Carnet {
private:
    vector<pair<string, T>> catalog;
public:
    Carnet& add(string mat, T nota) {
        catalog.push_back({mat, nota});
        return *this;
    }
    T operator[](string materie) {
        for (auto p: catalog) {
            if (p.first == materie)
                return p.second;
        }
        //string error_cout = "Nu exista nota pentru " + materie;
        throw exception();
    }
    Carnet& removeLast() {
        catalog.pop_back();
        return *this;
    }
};


#endif //CARNET_EX4_CARNET_H
