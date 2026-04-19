//
// Created by gabi on 4/15/26.
//

#ifndef PRACTICE_SEMINAR4_PLAYLIST_SONG_H
#define PRACTICE_SEMINAR4_PLAYLIST_SONG_H
#include <iostream>

using namespace std;

class Song {
private:
    string titlu;
    string artist;
    string gen;
    double durata;
public:
    Song(string title, string artist, string type, double duration): titlu{ title }, artist{ artist }, gen{ type }, durata{ duration }{};
    ~Song() = default;
    Song(const Song& other): titlu{ other.titlu }, artist{ other.artist }, gen{ other.gen }, durata{ other.durata }{};
    const string getTitlu() const;
    const string getArtist() const;
    const string getGen() const;
    const double getDurata() const;

    void setTitlu(string newTitle);
    void setArtist(string newArtist);
    void setGen(string newType);
    void setDurata(double newDuration);
};



#endif //PRACTICE_SEMINAR4_PLAYLIST_SONG_H
