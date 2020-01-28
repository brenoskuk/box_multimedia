#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include <iostream>
using namespace std;

#include "media.h"

class Photo : public Media {

public:

    // Destructor
    ~Photo();  // This is the destructor

    // Play Method
    /** Method play is declared as virtual in parent class. It uses system to open the imagej to show image.
     * To this end it concatenates a string and uses the c_str() method to obtain a pointer that
     * system can read.
     **/
    void play() const{
        // Concatenates srings to obtain argument
        system(("mpv" + this->getPath() +"&").c_str());
    }


    // Constructor
    Photo(string name, string path, double latitude, double longitude) : Media (name, path){
        this->latitude = latitude;
        this->longitude = longitude;
        cout << "Photo created" << endl;
    }

    Photo() : Media (){
        cout << "Photo created (standard)" << endl;
    }

    // Latitude and Longitude methods declared in Header
    void setLatLong( double latitude, double longitude){this->latitude = latitude; this->longitude = longitude;}

    void getLatLong(double & latitude, double & longitude) const {
        latitude = this->latitude;
        longitude = this->longitude;
    }

    void showLatLong(ostream& stre) const;




private:
    double latitude = 0;
    double longitude = 0;
};

#endif // PHOTO_H
