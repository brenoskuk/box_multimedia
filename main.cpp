//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "media.h"
#include "video.h"
#include "photo.h"

using namespace std;

int main(int argc, const char* argv[])
{

    std::cout << "Midia test" << std::endl;

    Video * v1 = new Video("video1", "samples/video_sample_1",1);
    Video * v2 = new Video();
    Photo * p1 = new Photo("photo1", "samples/lena.tif", 14.22, 22.34);
    Photo * p2 = new Photo();


    v2->setName("Video2");
    v2->setPath("samples/video_sample_2");
    v2->setPlaytime(1);
    p2->setPath("samples/lacornou.tif");
    p2->setLatLong(22.4444,22.592);


    std::cout << "Media 1 name: " << v1->getName() <<std::endl;
    std::cout << "Media 1 path: " << v1->getPath() <<std::endl;
    std::cout << "Media 2 name: " << p1->getName() <<std::endl;
    std::cout << "Media 2 path: " << p2->getPath() <<std::endl;

    double latitude, longitude;
    p2->getLatLong(latitude,longitude);

    std::cout << "Media 3 latitude: " << latitude <<std::endl;
    std::cout << "Media 3 name: " << p1->getName() <<std::endl;
    std::cout << "Media 3 path: " << p1->getPath() <<std::endl;

    std::cout << "\n\nOPENING FILES\n\n" <<std::endl;

    v1->play();
    p2->play();

    return 0;
}
