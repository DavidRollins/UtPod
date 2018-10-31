//DOCUMENT HERE

#include "Song.h"
#include <string>

using namespace std;
//Default constructor
//set the memory size to MAX_MEMORY
Song::Song()
{
    artist = "";
    title = "";
    size = MAX_MEM;

}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
Song::Song(string artist, string title, int size){
    this->artist = artist;
    this->title = title;
    this->size = size;
}

bool Song::operator< (const Song &rhs)
{
    if(title != rhs.title)
        return (title < rhs.title);
    if(artist != rhs.artist)
        return (artist < rhs.artist);
    if(size != rhs.size)
        return (size < rhs.size);
    return false;
}
bool Song::operator==(const Song &rhs)
{
    if(title != rhs.title)
        return false;
    if(artist != rhs.artist)
        return false;
    if(size != rhs.size)
        return false;
    return true;
}
bool Song::operator> (const Song &rhs)
{
    if(title != rhs.title)
        return (title > rhs.title);
    if(artist != rhs.artist)
        return (artist > rhs.artist);
    if(size != rhs.size)
        return (size > rhs.size);
    return false;
}




