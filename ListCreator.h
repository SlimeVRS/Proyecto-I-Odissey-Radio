#ifndef LISTCREATOR_H
#define LISTCREATOR_H

#include <string>
#include <fstream>
#include <utility>
#include <stdexcept>
#include <sstream>
#include "LinkedList.h"
#include "tracks.h"

LinkedList<Track> *readSmallMetadata(){
    LinkedList<Track> *tracks = new LinkedList<Track>();
    std::string SmallMeta;
    SmallMeta = "/home/marco/projects/helloworld.csv";
    std::ifstream filename(SmallMeta);
    if(!filename.is_open()){
        throw std::runtime_error("Could not open CSV file");
    }

    std::string line, data, title, genre;

    if(filename.good()){
        while(filename >> data){
            int i = 0;

            while(std::getline(filename, line)){
                std::stringstream ss(line);

                int colIdx = 0;

                Track *track = new Track();

                i++;

                while(std::getline(ss, data, ',')){
                    if(colIdx == 0){
                        track->setTrackID(data);
                    } else if(colIdx == 1){
                        track->setTitle(data);
                    } else if(colIdx == 2){
                        track->setArtist(data);
                    } else if(colIdx == 3){
                        track->setAlbum(data);
                    } else if(colIdx == 4){
                        track->setGenre(data);
                    }
                    colIdx++;
                }
                genre = track->getGenre();
                title = track->getTitle();
                bool genreStatus = (genre.find("genre_title") != std::string::npos);

                if(genreStatus && title.size() > 0 && genre.size() > 0){
                    tracks->insterElement(track);
                }
            }
        }
    }
    tracks->remove(0);
    return tracks;
}

#endif //LISTCREATOR_H