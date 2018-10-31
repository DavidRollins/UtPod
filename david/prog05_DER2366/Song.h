//DOCUMENT HERE

#ifndef SONG_H
#define SONG_H
#include <string>
using namespace std;
//UtPod class declaration
class Song
{
private:
    string artist;
    string title;
    int size;
    static const int MAX_MEM = 512;

public:
    //Default constructor
    //set the memory size to MAX_MEMORY
    Song();

    //Constructor with size parameter
    //The user of the class will pass in a size.
    //If the size is greater than MAX_MEMORY or less than or equal to 0,
    //set the size to MAX_MEMORY.
    Song(string artist, string title, int size);

    string getArtist() const
    {
        return artist;
    };
    string getTitle() const
    {
        return title;
    };
    int getSize() const
    {
        return size;
    };

    void setArtist(string name){
        artist = name;
    };

    void setTitle(string name){
        title = name;
    };

    void setSize(int n){
        size = n;
    };

    bool operator >(Song const &rhs);
    bool operator ==(Song const &rhs);
    bool operator <(Song const &rhs);


};



#endif