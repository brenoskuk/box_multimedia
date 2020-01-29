#include "manager.h"

MediaPtr Manager::newPhoto(string name, string path, double latitude, double longitude)
{
    auto it = mediaDict.find(name);
    if (it == mediaDict.end())
    {
        PhotoPtr pointer(new Photo(name, path, latitude, longitude));
        mediaDict[name] = pointer;
    }
    else
    {
        // stream error msg
    }
    return mediaDict[name];
}

MediaPtr Manager::newVideo(string name, string path, int playtime)
{
    auto it = mediaDict.find(name);
    if (it == mediaDict.end())
    {
        VideoPtr pointer(new Video(name, path, playtime));
        mediaDict[name] = pointer;
    }
    else
    {
        // stream error msg
    }
    return mediaDict[name];
}

MediaPtr Manager::newFilm(string name, string path, int playtime, int * chaps_lenghts, unsigned int n_chaps)
{
    auto it = mediaDict.find(name);
    if (it == mediaDict.end())
    {
        FilmPtr pointer(new Film(name, path ,playtime, chaps_lenghts, n_chaps));
        mediaDict[name] = pointer;
    }
    else
    {
        // stream error msg
    }
    return mediaDict[name];
}

GroupPtr Manager::newGroup(string name)
{
    auto it = groupDict.find(name);
    if (it == groupDict.end())
    {
        GroupPtr pointer(new Group(name));
        groupDict[name] = pointer;
    }
    else
    {
        // stream error msg
    }
    return groupDict[name];
}


void Manager::deleteMedia(string name)
{
    auto it = mediaDict.find(name);
    if (it != mediaDict.end())
    {
       // searches all groups that contain the media and removes it
       for (auto i = groupDict.begin(); i != groupDict.end(); i++)
           i->second->remove(it->second);
       // erases the media
       mediaDict.erase(it);
    }
}

void Manager::deleteGroup(string name)
{
    auto it = groupDict.find(name);
    if (it != groupDict.end())
    {
        // removes all media from group
        for (auto & i : *it->second)
        {
            it->second->remove(i);
        }
        groupDict.erase(it);
    }

}

void Manager::addFileToGroup(string mediaName, string groupName)
{
    MediaPtr pointerMedia;
    GroupPtr pointerGroup;

    // tries to find group and media
    pointerMedia = this->findMedia(mediaName);
    pointerGroup = this->findGroup(groupName);

    if(pointerGroup != nullptr || pointerMedia != nullptr)
    {
        pointerGroup->push_back(pointerMedia);
    }
    else
    {
        // something went wrong
    }

}


bool Manager::processRequest(TCPConnection &cnx, const string &request, string &response)
{
    cerr << "\nRequest: '" << request << "'" << endl;

    // Request parsing
    string action, name;
    stringstream str;
    str << request;
    str >> action;
    str >> name;

    // Locking ressources
    TCPLock lock(cnx);

    // Treating request
    stringstream answer_str;
    bool searched, played;
    searched = false;
    played = false;
    if (action == "search")
    {
       searched = this->showManagerMedia(name, answer_str);
       if (!searched)
       {
           searched = this->showManagerGroup(name, answer_str);
       }
    }
    if (action == "play")
    {
       playMedia(name);
    }

    // Sending response
    if(played || searched)
      response = answer_str.str();
    else
      response = "Error : no such file";
    cerr << "response: " << response << endl;

    return true;
}

