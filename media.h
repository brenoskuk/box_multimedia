#ifndef MEDIA_H
#define MEDIA_H
#include <string>
using namespace std;

class Media {

public:
    Media(string name, string path);  // This is the constructor
    Media();
    void setPath( string new_path );
    string getPath() const;
    void setName( string new_name );
    string getName() const;
    ~Media();  // This is the destructor
private:
    string path;
    string name;
};

#endif // MEDIA_H
