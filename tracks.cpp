#include "tracks.h"

Track::Track(){
    this->length = "00:30";
}

Track::~Track(){
    delete this;
}

void Track::setAlbum(std::string album){
    this->album = album;
}

void Track::setArtist(std::string artist){
    this->artist = artist;
}

void Track::setGenre(std::string genre){
    this->genre = genre;
}

void Track::setTitle(std::string title){
    this->title = title;
}

void Track::setTrackID(std::string trackID){
    this->trackID = trackID;
}

std::string Track::getAlbum(){
    return this->album;
}

std::string Track::getArtist(){
    return this->artist;
}

std::string Track::getGenre(){
    return this->genre;
}

std::string Track::getLenght(){
    return this->length;
}

std::string Track::getTitle(){
    return this->title;
}

std::string Track::getTrackID(){
    return this->trackID;
}