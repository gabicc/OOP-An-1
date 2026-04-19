//
// Created by gabi on 4/15/26.
//

#ifndef PRACTICE_SEMINAR4_PLAYLIST_REPO_H
#define PRACTICE_SEMINAR4_PLAYLIST_REPO_H

#include "Song.h"
#include <iostream>
#include <vector>

using namespace std;

class RepoSong {
private:
    vector<Song> songs;
public:
    RepoSong() = default;
    RepoSong(const RepoSong& other) = delete;
    const vector<Song>& getSongs();
    const Song& find(string title, string artist);
    void add(const Song& song);
};



#endif //PRACTICE_SEMINAR4_PLAYLIST_REPO_H
