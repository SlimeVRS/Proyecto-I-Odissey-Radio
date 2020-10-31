/**
 * @author Marco Rivera Serrano
 * @date 24/10/2020
 * @file tracks.h
 * @brief Setters and getters of each track
 */

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
    /**
     * @brief Gives the length of the track as "00:30"
     * @return The track with a lenght of "00:30"
     */ 
    Track();

    /**
     * @brief Deletes the track
     * @return The track deleted
     */ 
    ~Track();

    /**
     * @brief Sets the ID of the track
     * @param trackID the ID of the track
     * @return The track with the new ID
     */ 
    void setTrackID(std::string trackID);

    /**
     * @brief Sets the album of the track
     * @param album the album of the track
     * @return The track with the new album
     */ 
    void setAlbum(std::string album);

    /**
     * @brief Sets the title of the track
     * @param title the title of the track
     * @return The track with the new title
     */ 

    void setTitle(std::string title);

    /**
     * @brief Sets the artist of the track
     * @param artist the artist of the track
     * @return The track with the new artist
     */ 
    void setArtist(std::string artist);

     /**
     * @brief Sets the genre of the track
     * @param genre the genre of the track
     * @return The track with the new genre
     */    
    void setGenre(std::string genre);

    /**
     * @brief Gets the ID of the track
     * @return The ID of the track as a string
     */ 
    std::string getTrackID();

    /**
     * @brief Gets the album of the track
     * @return The ID album the track as a string
     */
    std::string getAlbum();

    /**
     * @brief Gets the title of the track
     * @return The title of the track as a string
     */
    std::string getTitle();

    /**
     * @brief Gets the artist of the track
     * @return The artist of the track as a string
     */
    std::string getArtist();

    /**
     * @brief Gets the length of the track
     * @return The length of the track as a string
     */
    std::string getLenght();

    /**
     * @brief Gets the genre of the track
     * @return The genre of the track as a string
     */
    std::string getGenre();
};

#endif //TRACKS_H