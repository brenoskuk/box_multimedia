//
// main.cpp
// Created on 21/10/2018
//


#include <memory>
#include <string>
#include <sstream>
#include "tcpserver.h"
#include <iostream>

#include "media.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "manager.h"

using namespace std;
using namespace cppu;

const int PORT = 3331;

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
    unsigned int n = 10;
    int * chaps = nullptr;
    chaps = new int [n];

    for (unsigned int k=0; k < n; k++)
    {
        chaps[k] = int(k);
        //cout << chaps[k] << endl;
    }

    Film * f = new Film ("film1", "samples/film1", 180,chaps, n);

    unsigned int n_chaps_new = f->getChapNumber();
    const int * chaps_new = f->getChapters();

    cout << "n chapters is "<< n_chaps_new << endl;

    for (unsigned int k=0; k < n_chaps_new; k++)
    {
        cout << chaps_new[k] << endl;
    }

    delete[] chaps;
    unsigned int n2 = 4;
    int * chaps2 = nullptr;
    chaps2 = new int [n2];
    chaps2[0] = 2;
    chaps2[1] = 8;
    chaps2[2] = 16;
    chaps2[3] = 64;

    f->setChapters(chaps2,n2);
    cout << "n chapters is "<< f->getChapNumber() << endl;

    for (unsigned int k=0; k < f->getChapNumber(); k++)
    {
        cout << f->getChapters()[k] << endl;
    }
    delete f;
}

void test9()
{
    shared_ptr<Video> v1 (new Video("video1", "samples/video_sample_1.mp4",1));
    shared_ptr<Video> v2 (new Video());
    shared_ptr<Photo> p1 (new Photo("photo1", "samples/lena.tif", 14.22, 22.34));
    shared_ptr<Photo> p2 (new Photo());

    unsigned int n = 10;
    int * chaps = nullptr;
    chaps = new int [n];

    for (unsigned int k=0; k < n; k++)
    {
        chaps[k] = int(k);
        //cout << chaps[k] << endl;
    }

    shared_ptr<Film> f (new Film ("film1", "samples/LOTR_ROTK", 280, chaps, n));

    shared_ptr<Group> gr1 (new Group ("Test group 1"));
    shared_ptr<Group> gr2 (new Group ("Test group 2"));

    gr1->push_back(v1);
    gr1->push_back(v2);
    gr1->push_back(p1);
    gr1->push_back(p2);
    gr1->push_back(f);

    cout << "print of group 1 : \n" << endl;
    if (gr1.use_count() != 0)
    {
        cout << "print of group 1 : \n" << endl;
        for (auto & it : *gr1)
        {
            cout<< "media name : "<< it->getName() << endl;
        }
    }

    gr2->push_back(p1);
    gr2->push_back(p2);

    cout << "print of group 2 : \n" << endl;
    if (gr2.use_count() != 0)
    {
        for (auto & it : *gr2)
        {
            cout<< "media name : "<< it->getName() << endl;
        }
    }
    gr1.reset();

    if (gr1.use_count() != 0)
    {
        cout << "print of group 1 : \n" << endl;
        for (auto & it : *gr1)
        {
            cout<< "media name : "<< it->getName() << endl;
        }
    }


    cout << "print of group 2 : \n" << endl;
    if (gr2.use_count() != 0)
    {
        for (auto & it : *gr2)
        {
            cout<< "media name : "<< it->getName() << endl;
        }
    }

}

void test10()
{

    // testing manager

    shared_ptr<Manager> m(new Manager());
    // testing media

    m->newVideo("video1", "samples/video_sample_1.mp4",1);
    m->newPhoto("photo1", "samples/lena.tif", 14.22, 22.34);
    m->newVideo("video2", "samples/video_sample_2.flv", 2);
    m->newPhoto("photo2", "samples/lacornou.tif", 55.5, 22.13);
    m->playMedia("video1");

    m->playMedia("photo2");
    // deleting media
    m->deleteMedia("video1");
    cout << "deletando" << endl;
    m->playMedia("video1");
    cout << "deletado" << endl;
    // testing groups

    m->newGroup("group1");
    m->newGroup("group2");
    m->addFileToGroup("video1","group1");
    m->addFileToGroup("group1","video2");
    m->addFileToGroup("photo1","group1");

    m->playMedia("photo1");
    m->deleteGroup("group1");
    m->playMedia("photo1");

}

// TESTS
//int main(int argc, const char* argv[])
//{
    //test5();
    //test6();
    //test9();
//}

int main(int argc, char* argv[])
{
    // cree le TCPServer
    shared_ptr<TCPServer> server(new TCPServer());

    // cree l'objet qui gère les données
    shared_ptr<Manager> base(new Manager());

    // le serveur appelera cette méthode chaque fois qu'il y a une requête
    server->setCallback(*base, &Manager::processRequest);

    // lance la boucle infinie du serveur
    cout << "Starting Server on port " << PORT << endl;
    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
    }

    return 0;
}
