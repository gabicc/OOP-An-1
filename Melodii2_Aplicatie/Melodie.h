//
// Created by gabi on 6/19/26.
//

#ifndef MELODII2_APLICATIE_MELODIE_H
#define MELODII2_APLICATIE_MELODIE_H

#include <iostream>
#include <string.h>

using namespace std;

class Melodie {
private:
    int id;
    string titlu;
    string artist;
    string gen;
public:
    // creem melodii care au id, titlu, artist si gen
    Melodie(int id, string titlu, string artist, string gen): id{id}, titlu{titlu}, artist{artist}, gen{gen} {};
    virtual ~Melodie() {

    };
    int getId() const{
        return id;
    }
    string getTitlu() const {
        return titlu;
    }
    string getArtist() const {
        return artist;
    }
    string getGen() const {
        return gen;
    }
    // pt cand vrem sa asociem o melodie cu o alta
    void operator=(Melodie& other) {
        id = other.id;
        titlu = other.titlu;
        artist = other.artist;
        gen = other.gen;
    }
};


#endif //MELODII2_APLICATIE_MELODIE_H
