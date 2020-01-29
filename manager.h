#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <memory>
#include <string>

#include "media.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"

using namespace std;

// defines shortcuts to shared_ptr
typedef shared_ptr<Media> MediaPtr;
typedef shared_ptr<Photo> PhotoPtr;
typedef shared_ptr<Video> VideoPtr;
typedef shared_ptr<Film> FilmPtr;
typedef shared_ptr<Group> GroupPtr;

// defines shortcuts to shared_ptr
typedef map<string, MediaPtr> MediaDict;
typedef map<string, GroupPtr> GroupDict;

// smart pointers to map
typedef shared_ptr<MediaDict> MediaDictPtr;
typedef shared_ptr<GroupDict> GroupDictPtr;

class Manager
{

public:

    // Manager constructor only initializes dicts as attributes
    Manager() : mediaDict(), groupDict(){}

    /**
      Each media type has a dedicated method for adding a new entry to the map.
      They individually call the constructor of each class.
      First they search if the map already has
      an object by the same name. If it does, prints a warning and does nothing.
      If it doesn't creates a new object, adds it to the Dict and returns
      a smart pointer to the object.
    **/
    MediaPtr newPhoto(string name, string path, double latitude, double longitude);

    MediaPtr newVideo(string name, string path, int playtime);

    MediaPtr newFilm(string name, string path, int playtime, int * chaps_lenghts, unsigned int n_chaps);

    GroupPtr newGroup(string name);

    /** Finding a group or a media is a simple search in the Dict
    **/
    MediaPtr findMedia(string name)
    {
        auto it = mediaDict.find(name);
        if (it != mediaDict.end())
        {
            cout << "check find media " << it->second->getName() << endl;
            return it->second;
        }
        else
        {
            // streams error
            return nullptr;
        }
    }

    GroupPtr findGroup(string name)
    {
        auto it = groupDict.find(name);
        if (it != groupDict.end())
        {
            return it->second;
        }
        else
        {
            // streams error
            return nullptr;
        }
    }

    /**
      Media are deleted by reseting the pointer in the corresponding dict.
      Smart pointers will make sure to call the right destructors.
      If a media is deleted, groups that contain it are taken into account.
    **/
    void deleteMedia(string name);

    /**
      Groups are deleted by erasing the pointer in the corresponding map.
      To avoid deletion of associated media, all entries of the group are removed
      before the erasure.
    **/
    void deleteGroup(string name);

    void addFileToGroup(string fileName, string groupName);

    void playMedia(string name)
    {
        MediaPtr pointer = this->findMedia(name);
        if (pointer != nullptr)
        {
            pointer->play();
        }
        else
        {
            // do something
        }
    }

private:
    MediaDict mediaDict;
    GroupDict groupDict;
};

#endif // MANAGER_H
