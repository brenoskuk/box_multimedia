#include "film.h"

void Film::setChapters(int *chapters, int n_chaps)
{
    delete[] this->chaps_lenghts;
    int * pl = nullptr;
    if (n_chaps!=0)
    {
        pl = new int [n_chaps];
        for (int i = 0; i < n_chaps; i++)
        {
            this->chaps_lenghts[i] = chapters[i];
        }
    }
    this->n_chaps = n_chaps;
}


/**
void Film::printMedia(std::ostream &str)
{
    str << "This file is a FILM \n"
        << "Path : " << this->getPath() << '\n'
        << "Media name : " << this->getName() << '\n'
        << "Duration : " << this->playtime << '\n'
        << "Number of chapters : " << this->n_chap << '\n';
    if (chapNb != 0)
    {
        str << "Chapters length :\n";
        for (int i = 0; i < chapNb; i++)
        {
        str << "Chapter " << i + 1 << " : " << chapters[i] << '\n';
        }
    }
    else
    {
        str << "No chapters specified \n";
    }
}
**/

void Film::showFilm()
{
    cout << "n chapters is "<< this->n_chaps << endl;
    for (int k=0; k < this->n_chaps; k++)
    {
        cout << this->chaps_lenghts[k] << endl;
    }
}

// Must delete all chapters
Film::~Film()
{
    delete[] this->chaps_lenghts;
}

