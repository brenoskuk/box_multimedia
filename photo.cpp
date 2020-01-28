#include "photo.h"
#include <iostream>

// DESTRUCTOR
Photo::~Photo()
{
   cout << "Media deleted)" << endl;
}

void Photo::play() const
{
    // Concatenates strings to obtain argument
    //cout << "Showing video..." << endl;
    string command ("imagej " + this->getPath() +" &");
    //cout << command << endl;
    system(command.c_str());
}
