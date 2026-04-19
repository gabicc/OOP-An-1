//
// Created by gabi on 4/15/26.
//

#ifndef PRACTICE_SEMINAR4_PLAYLIST_VALIDATOR_H
#define PRACTICE_SEMINAR4_PLAYLIST_VALIDATOR_H

#include "Song.h"
#include <iostream>
#include <vector>

using namespace std;

class SongValidator {

public:
    void validator(const Song& s) {
        vector<string> errorMsg;
        if (s.getTitlu().length() == 0) {
            errorMsg.push_back("Titlul nu poate fi vid");
        }
        if (s.getArtist().length() == 0) {
            errorMsg.push_back("Artistul nu poate fi vid");
        }
        if (s.getGen().length() == 0) {
            errorMsg.push_back("Genul nu poate fi vid");
        }
        if (s.getDurata() <= 0) {
            errorMsg.push_back("Durata nu poate fi negativa");
        }
        if (errorMsg.size() > 0) {
            string allErrors = "";
            for (const string& e: errorMsg) {
                allErrors += e + '\n';
            }
            cout << allErrors << '\n';
        }
    }
};



#endif //PRACTICE_SEMINAR4_PLAYLIST_VALIDATOR_H
