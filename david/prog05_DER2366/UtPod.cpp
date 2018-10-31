//DOCUMENT HERE

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "UtPod.h"
#include "Song.h"
using namespace std;
//UtPod class declaration

//Default constructor
//set the memory size to MAX_MEMORY


//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size){
    if(size > MAX_MEMORY || size <= 0) {
        memSize = MAX_MEMORY;
    }else{
        memSize = size;
        songs = NULL;
    }

}
/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song

 precondition: s is a valid Song

 input parms -

 output parms -
*/

int UtPod::addSong(Song const &song){
    //cout << song.getSize() + memoryUsed() << endl;
    if(((song.getSize() + memoryUsed() > memSize) && songs != NULL) || song.getSize() == 0){
        return NO_MEMORY;
    } else {


        SongNode *newNode;
        SongNode *nodePtr;


        newNode = new SongNode;
        newNode->s = song;
        newNode->next = NULL;

        // If empty, make newNode the first node
        if (songs == NULL) {
            songs = newNode;
           // memSize = 0;
        }
        else
        {

            nodePtr = songs;
            // traverse list to find last node
            while (nodePtr->next!=NULL) {
                nodePtr = nodePtr->next;
            }
            nodePtr->next = newNode;
        }
       // memSize += song.getSize();
        return SUCCESS; // return success

    }

}


/* FUNCTION - int removeSong
 * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
     o returns 0 if successful
     o returns -1 if nothing is removed


   input parms -

   output parms -
*/

int UtPod::removeSong(Song const &song){

    bool song_exists;
    // keep trying to remove one, until there are no more
    song_exists = remove(song);
    while (song_exists) // if song found, remove
    {
        song_exists = remove(song);
        //memSize -= song.getSize(); // decrease memory used
        return SUCCESS; // return successful
    }
    return NOT_FOUND; // return unsuccessful
}

bool UtPod::remove(Song song)
{
    SongNode *nodePtr = songs;
    SongNode *previousNode = NULL;
    while (nodePtr)
    {
        if (nodePtr->s == song) // if song matchs is found, delete song
        {
            if (previousNode == NULL) // if node reaches end of list
                songs = nodePtr->next;
            else
                previousNode->next = nodePtr->next;

            delete nodePtr; // deletes song
            return true;
        }
        previousNode = nodePtr; //else: advance both pointers
        nodePtr = nodePtr->next;
    }
    return false;
}

/* FUNCTION - void shuffle
 *  shuffles the songs into random order
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/

int UtPod::numSongs(SongNode *head){
    int count;
    SongNode* p = head;
    while (p != NULL)
    {
        ++count;
        p = p->next;
    }
    return count;
}
void UtPod::shuffle(){

    srand(time(NULL));

    int randomNum; // stores random number
    SongNode *prevSong, *swapSong, *ptr1, *ptr2; // pointers to travel
    //the list
    Song buffer; // buffer to store song temporarily
    int newNumber = numSongs(songs);
    ptr1 = songs; // sets pointer 1 to beginning of song list

    for(int a = 0; a < newNumber; a++)
    {
        // traverse to newNumber position in song list
        ptr2 = songs;// start at beginning
        prevSong = ptr1;
        randomNum = (rand() % newNumber) + 1; // generates random number
        // but not 0

        for(int k = 1; k <= randomNum; k++)
        {

            if(k == randomNum || ptr2 == NULL) // when k matches random number do not switch
            if (ptr2 == NULL) ptr2 = songs;
                swapSong = ptr2; // set swapSong equal to pointer2
                ptr2 = ptr2->next; // traverse to next song

            }

        //swapping of songs
        if(ptr1 != NULL) {
            buffer = prevSong->s; // prevSong stored in buffer

            prevSong->s = swapSong->s;
            swapSong->s = buffer;
            ptr1 = ptr1->next;
        }

    }

}


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)

   input parms -

   output parms -
*/

void UtPod::showSongList()
{
    SongNode *nodePtr; // pointer used to traverse the list
    nodePtr = songs; // sets node to beginning of list

    while (nodePtr) // traverses through all elements in the list.
    {
        // displays list contents
        cout << "Title: " << nodePtr->s.getTitle()
             << "    Artist: " << nodePtr->s.getArtist()
             << "    Size: " << nodePtr->s.getSize() << endl;
        //moves to next song
        nodePtr = nodePtr->next;
    }
}


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/

void UtPod::sortSongList(){
    SongNode *buff; // buff initialized
    buff = NULL; // set to NULL
    SongNode *pointer;  // pointer to traverse song list

    while(songs) //Loop is executed as long as there are movies in movieList
    {
        // Allocate a new node for song.
        SongNode *newNode; // create node
        newNode = new SongNode; // create new songNode
        newNode->s = searchLeast(); // newNode equal to lowest value vound
        newNode->next = NULL;

        // Remove lowest song found
        remove(searchLeast());

        // If empty, make newNode first node.
        if (!buff)
            buff = newNode;
        else
        {
            // make pointer to head of buff list.
            pointer = buff;

            // traverse list to find last node in buff.
            while(pointer->next)
                pointer = pointer->next;
            // makes last node point to newNode
            pointer->next = newNode;
        }
    }
    //makes old head point to new head.
    songs = buff;
}


/* FUNCTION - void clearMemory
 * clears all the songs from memory

   input parms -

   output parms -
*/
void UtPod::clearMemory(){
    SongNode *temp;
    temp  = songs; // temp set to beginning
    while(temp != NULL) // while temp has not reached end
    {
        songs->next = temp->next;
        temp->next = NULL;
        delete temp; // deletes temp songNode
        temp = songs->next;
    }
    songs = NULL; // no songs in list

}


Song UtPod::searchLeast()
{
    SongNode *nodePtr; // to traverse list of songs.
    nodePtr = songs;
    Song temp = nodePtr->s; // initializes temp and sets
    // values of song to temp
    nodePtr = nodePtr->next; //points node to next song in list.

    while(nodePtr) // while node available to traverse.
    {
        if(nodePtr->s < temp) //comparison of song values.
            temp = nodePtr->s; // set temp song to value of node
        nodePtr = nodePtr->next; // node set values of next song
    }
    return temp; // return lowest valued song
}

/* FUNCTION - int getTotalMemory
 *  returns the total amount of memory in the UtPod
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/


int UtPod::memoryUsed(){
    SongNode *ptr = songs;
    int memUsed = 0;

    while(ptr!=NULL){

        memUsed += ptr->s.getSize();
        ptr = ptr->next;
    }

    return memUsed;
}

/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs

   input parms -

   output parms -
*/

int UtPod::getRemainingMemory(){

      return getTotalMemory() - memoryUsed();
    }


UtPod::~UtPod(){
    clearMemory();
}


