//
// Created by gabi on 4/15/26.
//

#include "Song.h"

const string Song::getTitlu() const {
    return this->titlu;
}
const string Song::getArtist() const {
    return this->artist;
}
const string Song::getGen() const {
    return this->gen;
}
const double Song::getDurata() const {
    return this->durata;
}

void Song::setTitlu(string newTitle) {
    this->titlu = newTitle;
}
void Song::setArtist(string newArtist) {
    this->artist = newArtist;
}
void Song::setGen(string newType) {
    this->gen = newType;
}
void Song::setDurata(double newDuration) {
    this->durata = newDuration;
}