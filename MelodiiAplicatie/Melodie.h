//
// Created by gabi on 6/18/26.
//

#ifndef MELODIIAPLICATIE_MELODIE_H
#define MELODIIAPLICATIE_MELODIE_H

#include <iostream>
#include <string.h>
using namespace std;

class Melodie {
private:
    int id;
    string titlu;
    string artist;
    int rank;
    // clasa Melodie are 4 atribute: id - int, titlu - string, artist - string, rank - int
public:
    Melodie(int id1, string titlu1, string artist1, int rank1): id{id1}, titlu{titlu1}, artist{artist1}, rank{rank1} {};
    // constructor melodie
    virtual ~Melodie() {

    };
    // destructor melodie
    int getId() {
        return id;
    }
    string getTitlu() {
        return titlu;
    }
    string getArtist() {
        return artist;
    }
    int getRank() {
        return rank;
    }
    void operator=(const Melodie& m) {
        this->id = m.id;
        this->titlu = m.titlu;
        this->artist = m.artist;
        this->rank = m.rank;
    }
    // pt cand vrem sa atribuim o melodie alteia
};


#endif //MELODIIAPLICATIE_MELODIE_H
