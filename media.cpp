#include "media.h"
#include <iostream>

// Member functions definitions including constructor


// Constructor
Media::Media(string name, string path)
{
    this->name = name;
    this->path = path;
    //cout << "Media created" << endl;
}

Media::Media()
{
   cout << "Media created" << endl;
}

// Name methods
void Media::setName( string new_name )
{
   this->name = new_name;
}

string Media::getName() const
{
    return this->name;
}

// Path methods
void Media::setPath( string new_path )
{
    this->path = new_path;
}

string  Media::getPath() const
{
    return this->path;
}

// DESTRUCTOR
Media::~Media() {
}








