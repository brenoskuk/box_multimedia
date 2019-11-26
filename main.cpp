//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "media.h"

using namespace std;

int main(int argc, const char* argv[])
{

    std::cout << "Midia test" << std::endl;

    Media * c = new Media("audio", "ad11");
    Media * d = new Media("video", "sop442");

    Media * v = new Media();

    d->setName("new_video");
    v->setName("SONG");
    v->setPath("SONGPATH");


    std::cout << "Media 1 name: " << c->getName() <<std::endl;
    std::cout << "Media 1 path: " << c->getPath() <<std::endl;
    std::cout << "Media 2 name: " << d->getName() <<std::endl;
    std::cout << "Media 2 path: " << d->getPath() <<std::endl;
    std::cout << "Media 3 name: " << v->getName() <<std::endl;
    std::cout << "Media 3 path: " << v->getPath() <<std::endl;
    return 0;
}
