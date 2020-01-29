#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include <iostream>
using namespace std;

#include "media.h"

class Photo : public Media
{

public:

    // Destructor
    ~Photo() override;  // This is the destructor

    // Constructor
    Photo(string name = "", string path = "", double latitude = 0,
          double longitude = 0) : Media (name, path)
    {
        this->latitude = latitude;
        this->longitude = longitude;
        cout << "Photo created" << endl;
    }

    // Latitude and Longitude methods declared in Header
    void setLatLong( double latitude, double longitude)
    {
        this->latitude = latitude; this->longitude = longitude;
    }

    void getLatLong(double & latitude, double & longitude) const
    {
        latitude = this->latitude;
        longitude = this->longitude;
    }

    void showLatLong(ostream& stre) const;

    // Play Method
    /** Method play is declared as virtual in parent class. It uses system to open the imagej to show image.
     * To this end it concatenates a string and uses the c_str() method to obtain a pointer that
     * system can read.
     **/
    void play() const override;

    // Show Method
    void showMedia(ostream& stream) const override;

private:
    double latitude = 0;
    double longitude = 0;
};

#endif // PHOTO_H
