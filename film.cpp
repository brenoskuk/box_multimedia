#include "film.h"

void Film::setChapters(int *chapters, unsigned int n_chaps)
{
    delete[] this->chaps_lenghts;
    if (n_chaps!=0)
    {
        for (unsigned int i = 0; i < n_chaps; i++)
        {
            this->chaps_lenghts[i] = chapters[i];
        }
    }
    this->n_chaps = n_chaps;
}


void Film::showFilm()
{
    cout << "n chapters is "<< this->n_chaps << endl;
    for (unsigned int k=0; k < this->n_chaps; k++)
    {
        cout << this->chaps_lenghts[k] << endl;
    }
}

// Must delete all chapters
Film::~Film()
{
    delete[] this->chaps_lenghts;
}

void Film::showMedia(ostream& str) const
{
    str << "Media type : Film \n"
        << "Media name : " << this->getName() << "\n"
        << "Media path : " << this->getPath() << "\n"
        << "Playtime   : " << this->getPlaytime() << "\n";
    if (this->n_chaps != 0)
    {
        str << "Chapters   : " << this->n_chaps << "\n"
            << "Lenght of chapters:" << "\n";
        for (unsigned int k = 0; k < this->n_chaps; k++)
        {
        str << "Chapter " << k + 1 << " has lenght : " << this->chaps_lenghts[k] << "\n";
        }
    }
    else
    {
        str << "There are no chapters\n";
    }
}

