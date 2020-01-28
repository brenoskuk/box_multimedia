#include "video.h"
#include <iostream>

// DESTRUCTOR
Video::~Video()
{
   cout << "Media deleted)" << endl;
}

void Video::play() const
{
    // Concatenates strings to obtain argument
    //cout << "Playing video..." << endl;
    string command ("mpv " + this->getPath() + "&");
    //cout << command << endl;
    system(command.c_str());
}
