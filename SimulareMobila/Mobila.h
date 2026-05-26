//
// Created by gabi on 5/19/26.
//

#ifndef SIMULAREMOBILA_MOBILA_H
#define SIMULAREMOBILA_MOBILA_H

#include <string.h>
#include <iostream>

using namespace std;

class Mobila {
private:
    int id;
    string type;
    int nr_pieces;
    int assembly_time;
public:
    Mobila(int id, string type, int nr_pieces, int assembly_time): id{id}, type{type}, nr_pieces{nr_pieces}, assembly_time{assembly_time} {};
    virtual ~Mobila() {

    }
    int getId() const {
        return this->id;
    }
    string getType() const {
        return this->type;
    }
    int getNrPieces() const {
        return this->nr_pieces;
    }
    int getAssemblyTime() const {
        return this->assembly_time;
    }
    void operator=(const Mobila& other) {
        this->id = other.id;
        this->type = other.type;
        this->nr_pieces = other.nr_pieces;
        this->assembly_time = other.assembly_time;
    }
};


#endif //SIMULAREMOBILA_MOBILA_H
