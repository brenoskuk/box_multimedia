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
typedef map<string, MediaPtr> MediaMap;
typedef map<string, GroupPtr> GroupMap;

// smart pointers to map
typedef shared_ptr<MediaMap> MediaMapPtr;
typedef shared_ptr<GroupMap> GroupMapPtr;

class Manager
{

public:

    Manager(MediaMap mediaMap, GroupMap groupMap);

    /**
      Each media type has a dedicated method for adding a new entry to the map.
      They individually call the constructor of each class.
      First they create a new object. Then they search if the map already has
      an object by the same name. If it does, deletes it using smart pointer
      operator reset. Then maps the object to it's name.
      Finally, returns a smart pointer to the object type.
    **/
    MediaPtr newPhoto(string name, string path, int latitude, int longitude)
    {
        PhotoPtr pointer(new Photo(name, path, latitude, longitude));
        mediaMap[name] = pointer;
        if (pointer.use_count() != 0)
        {
            pointer.reset();
        }
        return mediaMap[name];
    }
    MediaPtr newVideo(string name, string path, int playtime)
    {
        VideoPtr pointer(new Video(name, path, playtime));
        mediaMap[name] = pointer;
        if (pointer.use_count() != 0)
        {
            pointer.reset();
        }
        return mediaMap[name];
    }
    MediaPtr newFilm(string name, string path, int playtime, int * chaps_lenghts, unsigned int n_chaps)
    {
        FilmPtr pointer(new Film(name, path ,playtime, chaps_lenghts, n_chaps));
        mediaMap[name] = pointer;
        if (pointer.use_count() != 0)
        {
            pointer.reset();
        }
        return mediaMap[name];
    }
    GroupPtr newGroup(string name)
    {
        GroupPtr pointer(new Group(name));
        groupMap[name] = pointer;
        if (pointer.use_count() != 0)
        {
            pointer.reset();
        }
        return groupMap[name];
    }

    /**
      Media and Groups are deleted by reseting the pointer in the corresponding map.
      Smart pointers will make sure to call the right destructors.
    **/
    void deleteMedia(string name)
    {
        auto it = mediaMap.find(name);
           if (it != mediaMap.end())
           {
               for (auto i = groupMap.begin(); i != groupMap.end(); i++)
                   i->second->remove(it->second);
               mediaMap.erase(it);
           }
    }
    void deleteGroup(string name);

    void addFileToGroup(string fileName, string groupName);
    void playMedia(string name);

private:
    MediaMap mediaMap;
    GroupMap groupMap;
};

#endif // MANAGER_H
