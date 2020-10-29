#ifndef TRACKS_H
#define TRACKS_H

#include <iostream>
#include <string>

class Track {
private:
    std::string trackID;
    std::string album;
    std::string title;
    std::string artist;
    std::string length;
    std::string genre;

public:
    Track();
    ~Track();

    void setTrackID(std::string trackID);
    void setAlbum(std::string album);
    void setTitle(std::string title);
    void setArtist(std::string artist);
    void setGenre(std::string genre);

    std::string getTrackID();
    std::string getAlbum();
    std::string getTitle();
    std::string getArtist();
    std::string getLenght();
    std::string getGenre();
};

#endif //TRACKS_H