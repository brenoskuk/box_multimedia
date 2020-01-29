#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <memory>
#include <string>
#include <iostream>
using namespace std;

#include "media.h"
/**
 * @brief The Group class inherits from list of objects of type Media.
 * See list documentation.
 */
class Group :  public list<shared_ptr<Media>>
{
public:

    // Constructor of group
    Group(string name)
    {
        this->name = name;
    }

    // Methods of Group
    string getName()
    {
        return this->name;
    }

    // Delete of Group
    ~Group(){}

    // Showing group
    void showGroup(ostream& str)
    {
        str << "Group name : " << name << "\n";
        for (std::shared_ptr<Media> media : *this)
        {
            int k = 1;
            str << "Group number" << k << "name : " << name << "\n";
            k++;
            media->showMedia(str);
        }
    }

private:
    string name;
};

#endif // GROUP_H
