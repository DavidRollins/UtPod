/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    Song s1;
    s1.setArtist("ABBA");
    s1.setTitle("Dancing Queen");
    s1.setSize(25);

    Song s2("ABBA", "Dancing Queen", 25);


    cout << "ABBA's Dancing Queen is ABBA's Dancing Queen: " << (s1==s2) << endl;

    s2.setSize(40);
    cout << "ABBA's Dancing Queen is ABBA's Dancing Queen: " << (s1==s2) << endl;

    cout << "ABBA's Dancing Queen (extended) is after ABBA's Dancing Queen: " << (s1<s2) << endl;

    Song s3("Britney Spears", "Toxic", 40);

    UtPod DavidsPod;

    int result = DavidsPod.addSong(s1);
    cout << "result = " << result << endl;


    result = DavidsPod.addSong(s2);
    cout << "result = " << result << endl;


    result = DavidsPod.addSong(s3);
    cout << "result = " << result << endl;

    DavidsPod.showSongList();
    cout << "memory = " << DavidsPod.getRemainingMemory() << endl;

    Song s4("ACDC", "Highway to Hell", 300);
    Song s5("ACDC", "Thunderstruck", 10);

    cout << "ACDC Highway to Hell is before Thunderstruck: " << (s4<s5) << endl;
    cout << "--------------------------" << endl;

    DavidsPod.addSong(s4);
    DavidsPod.addSong(s5);

    DavidsPod.showSongList();
    cout << "memory = " << DavidsPod.getRemainingMemory() << endl;
    cout << "--------------------------" << endl;

    DavidsPod.shuffle();
    DavidsPod.showSongList();
    cout << "--------------------------" << endl;
    DavidsPod.sortSongList();
    DavidsPod.showSongList();
    cout << "--------------------------" << endl;

    DavidsPod.removeSong(s2);
    DavidsPod.removeSong(s5);

    DavidsPod.showSongList();
    cout << "--------------------------" << endl;
    DavidsPod.shuffle();
    DavidsPod.remove(s1);
    DavidsPod.showSongList();
    cout << "--------------------------" << endl;
    DavidsPod.sortSongList();
    DavidsPod.showSongList();
    cout << "--------------------------" << endl;
    cout << "memory = " << DavidsPod.getRemainingMemory() << endl;

    DavidsPod.clearMemory();
    DavidsPod.showSongList();
    /*
     * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     */

    UtPod RogersPod(250);

    RogersPod.addSong(s2);
    RogersPod.addSong(s1);
    RogersPod.addSong(s5);
    RogersPod.showSongList();
    cout << "memory = " << RogersPod.getRemainingMemory() << endl;
    cout << "--------------------------" << endl;
    RogersPod.sortSongList();
    RogersPod.showSongList();
    cout << "--------------------------" << endl;
    RogersPod.shuffle();
    RogersPod.showSongList();
    cout << "--------------------------" << endl;


    //Song s6("Eminem", "Til I Collapse", 250);
   
    s4.setSize(250);
    result = RogersPod.addSong(s4);
    cout << "result = " << result << endl;

    RogersPod.removeSong(s1);
    RogersPod.showSongList();
    cout << "--------------------------" << endl;
    RogersPod.clearMemory();
    RogersPod.showSongList();
    cout << "memory = " << RogersPod.getRemainingMemory() << endl;
/*
 *
    UtPod t(500);

    Song s1("Beatles", "Hey Jude1", 4);

    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    */
/*
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

*/
  //  t.shuffle();
   // t.showSongList();
/*
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    t.sortSongList();
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    t.clearMemory();
    cout << "memory = " << t.getRemainingMemory() << endl;
*/
}
