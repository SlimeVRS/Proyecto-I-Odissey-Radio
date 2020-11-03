/**
 * @author Marco Rivera Serrano
 * @date 24/10/2020
 * @file ListCreator.h
 * @brief Creates a list to be used in the ui
 */

#ifndef LISTCREATOR_H
#define LISTCREATOR_H

#include <string>
#include <fstream>
#include <utility>
#include <stdexcept>
#include <sstream>
#include "LinkedList.h"
#include "tracks.h"

/**
 * @brief This methods gives a linked list with all the rows in the csv file.
 * @return A linked list with the songs in the csv file.
 */
LinkedList<Track> *readSmallMetadata(){
    LinkedList<Track> *tracks = new LinkedList<Track>();    // Final list
    std::string SmallMeta;
    SmallMeta = "/home/marco/projects/helloworld.csv";      // Directory of the csv file
    std::ifstream filename(SmallMeta);
    if(!filename.is_open()){                                // Exception if file isn't open
        throw std::runtime_error("Could not open CSV file");
    }

    std::string line, data, title, genre;                   // Variables to be used

    if(filename.good()){                                    // Check if the directory is well written
        while(filename >> data){
            int i = 0;

            while(std::getline(filename, line)){            // Get the line in the file
                std::stringstream ss(line);

                int colIdx = 0;

                Track *track = new Track();

                i++;

                while(std::getline(ss, data, ',')){         // Divide the line in columns acording to the comma (,)
                    if(colIdx == 0){
                        track->setTrackID(data);            // Sets the first column as the ID of the song
                    } else if(colIdx == 1){
                        track->setTitle(data);              // Sets the second column as the title of the song
                    } else if(colIdx == 2){
                        track->setArtist(data);             // Sets the third column as the artist of the song
                    } else if(colIdx == 3){
                        track->setAlbum(data);              // Sets the fourth column as the Album of the song
                    } else if(colIdx == 4){
                        track->setGenre(data);              // Sets the fiveth column as the genrev
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
    tracks->remove(0);                                      // Removes the header of the list
    return tracks;
}
LinkedList<Track> *readSmallArtist(std::string artist, LinkedList<Track> *result){
    NodeLL<Track> *current = result->getFirst();
    while(current->getNext() != nullptr){
        if(current->getData()->getArtist() != artist){
            result->remove(current);
            current = current->getNext();
        }
        else{
            current = current->getNext();
        }
    }
    return result;
}

LinkedList<Track> *ArtistList(LinkedList<Track> *list){
    LinkedList<Track> *Artists = new LinkedList<Track>();
    NodeLL<Track> *current = list->getFirst()->getNext();
    Artists->insterElement(list->getFirst()->getData());
    while(current != nullptr){
        NodeLL<Track> *Aux = Artists->getFirst();
        while(Aux != nullptr){
            if(Aux->getData()->getArtist() == current->getData()->getArtist()){
                current = current->getNext();
            } else {
                Aux = Aux->getNext();
            }
        }
        Artists->insterElement(current->getData());
        current = current->getNext();
    }
    return Artists;
}

#endif //LISTCREATOR_H
