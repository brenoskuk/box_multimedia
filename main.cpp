//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "media.h"
#include "photo.h"
#include "video.h"
#include "film.h"


using namespace std;

void test5()
{
    cout << "Midia test" << endl;

    Video * v1 = new Video("video1", "samples/video_sample_1.mp4",1);
    Video * v2 = new Video();
    Photo * p1 = new Photo("photo1", "samples/lena.tif", 14.22, 22.34);
    Photo * p2 = new Photo();

    // Test of setters

    v2->setName("Video2");
    v2->setPath("samples/video_sample_2.flv");
    v2->setPlaytime(1);
    p2->setPath("samples/lacornou.tif");
    p2->setLatLong(22.4444,22.592);


    cout << "\nTest of loop with polymorphism:\n\n" <<endl;

    // Test of loop with polymorphism

    Media ** medias = new Media * [10];

    int count = 0;
    medias[count ++] = v1;
    medias[count ++] = p1;
    medias[count ++] = v2;
    medias[count ++] = p2;


    for (int k=0; k < count; k++)
    {
        cout << "/nMedia "<< k << " has name: " << medias[k]->getName() <<endl;
        cout << "Media "<< k << " has path: " << medias[k]->getPath() << "\n" <<endl;
        medias[k]->play();
    }

    // Deletions
    delete[] medias;
}

void test6()
{
    int n = 10;
    int * chaps = nullptr;
    chaps = new int [n];

    for (int k=0; k < n; k++)
    {
        chaps[k] = k;
        //cout << chaps[k] << endl;
    }

    Film * f = new Film ("film1", "samples/film1", 180,chaps, n);

    int n_chaps_new = f->getChapNumber();
    const int * chaps_new = f->getChapters();

    cout << "n chapters is "<< n_chaps_new << endl;

    for (int k=0; k < n_chaps_new; k++)
    {
        cout << chaps_new[k] << endl;
    }

    delete[] chaps;
    int n2 = 4;
    int * chaps2 = nullptr;
    chaps2 = new int [n2];
    chaps2[0] = 2;
    chaps2[1] = 8;
    chaps2[2] = 16;
    chaps2[3] = 64;

    f->setChapters(chaps2,n2);
    cout << "n chapters is "<< f->getChapNumber() << endl;

    for (int k=0; k < f->getChapNumber(); k++)
    {
        cout << f->getChapters()[k] << endl;
    }
    delete f;
}

int main(int argc, const char* argv[])
{
    //test5();
    test6();
    return 0;
}
