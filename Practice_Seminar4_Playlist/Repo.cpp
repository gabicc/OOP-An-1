//
// Created by gabi on 4/15/26.
//

#include "Repo.h"

const vector<Song>& RepoSong::getSongs() {
    return this->songs;
}

const Song& RepoSong::find(string title, string artist) {
    for (const Song& song: this->songs) {
        if (song.getTitlu() == title && song.getArtist() == artist) {
            return song;
        }
    }

}

void RepoSong::add(const Song& song) {
    for (const Song& s: this->songs) {
        if (s.getTitlu() == song.getTitlu() && s.getArtist() == song.getArtist()) {
            cout << "Song already exists" << '\n';
            return;
        }
    }
    this->songs.push_back(song);
}