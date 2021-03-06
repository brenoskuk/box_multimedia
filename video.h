#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>
using namespace std;

#include "media.h"

class Video : public Media
{

public:

    // Destructor
    ~Video() override;

    // Constructor
    Video(string name = "", string path = "", int playtime = 0) : Media (name, path)
    {
        this->playtime = playtime;
        cout << "Video created" << endl;
    }

    // playtime methods declared in Header
    void setPlaytime( int playtime)
    {
        this->playtime = playtime;
    }

    int getPlaytime() const
    {
        return this->playtime;
    }

    void showPlaytime(ostream& stre) const;

    // Play Method
    /** Method play is declared as virtual in parent class. It uses system to open the mpv video player.
     * To this end it concatenates a string and uses the c_str() method to obtain a pointer that
     * system can read.
     **/
    void play() const override;

    // Show Method
    void showMedia(ostream& stream) const override;

private:
    int playtime = 0;

};

#endif // VIDEO_H
