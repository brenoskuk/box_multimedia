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
    void showName(ostream& stre) const;

    // Destructor
    virtual ~Media();  // This is the destructor

    // VIRTUAL METHOD play used in inherited classes
    virtual void play() const = 0;

private:
    string path = "";
    string name = "";
};

#endif // MEDIA_H
