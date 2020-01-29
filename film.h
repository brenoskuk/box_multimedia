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
         int * chaps_lenghts = nullptr , unsigned int n_chaps = 0) : Video(name, path, playtime){

        int * pl = nullptr;
        if (n_chaps!=0)
        {
            pl = new int [n_chaps];
            for (unsigned int i = 0; i < n_chaps; i++)
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
    void setChapters(int * chapter, unsigned int n_chap);

    unsigned int getChapNumber()
    {
        return this->n_chaps;
    }

    // Show method
    void showFilm();

    // Deep coopying

    Film(const Film& from);

    Film& operator=(const Film& from);

    // Destructor must take into account each chapter
    ~Film() override;

    void showMedia(ostream& stream) const override;

private :
    int * chaps_lenghts = nullptr;
    unsigned int n_chaps = 0;
};
#endif // FILM_H
