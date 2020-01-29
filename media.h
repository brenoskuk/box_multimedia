#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <iostream>
using namespace std;

// Media is a virtual class
class Media
{

public:


    // Constructor
    Media(string name = "", string path = "");  // This is the constructor

    Media();

    // Path methods
    void setPath( string new_path );

    string getPath() const;

    void showPath(ostream& stre) const;

    // Name methods
    void setName( string new_name );

    string getName() const;

    // Destructor
    virtual ~Media();  // This is the destructor

    // VIRTUAL METHOD play and printMedia used in inherited classes

    virtual void play() const = 0;

    /** Show method prints media type, name, path
     * and all aditional information of media in stream format
     **/
    virtual void showMedia(ostream& stream) const = 0;

private:
    string path = "";
    string name = "";
};

#endif // MEDIA_H
