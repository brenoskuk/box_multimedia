#ifndef FILM_H
#define FILM_H

#include <string>
#include <iostream>
using namespace std;

#include "video.h"

class Film : public Video
{
public:
    // Constructor of video
    Film(string name = "", string path = "", int playtime = 0,
         int * chaps_lenghts = nullptr , int n_chaps = 0) : Video(name, path, playtime){

        int * pl = nullptr;
        if (n_chaps!=0)
        {
            pl = new int [n_chaps];
            for (int i = 0; i < n_chaps; i++)
            {
              pl[i] = chaps_lenghts[i];
            }
        }
        this->n_chaps = n_chaps;
        this->chaps_lenghts = pl;
    }

    // Chapters methods

    /** The method getChapters returns a constant vector. This way
     *  only objects of type Film can modify it.
    **/
    const int * getChapters()
    {
        return this->chaps_lenghts;
    }

    /** The method setChapters first deletes existing chapters and then adds
     * them one by one to a new vector.
    **/
    void setChapters(int * chapter, int n_chap);

    int getChapNumber()
    {
        return this->n_chaps;
    }

    // Show method
    void showFilm();

    // Destructor must take into account each chapter
    ~Film();

private :
    int * chaps_lenghts = nullptr;
    int n_chaps = 0;
};
#endif // FILM_H
