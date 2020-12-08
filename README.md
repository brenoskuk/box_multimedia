# box multimedia


## C++

I. The Media class is set to a virtual type since we want to use polymorphism of heritage to generalize the usage of the play method. This method is thus virtual. We need to override the method in the inherited classes.
The method is declared at the header of each class so there is no need to modify makefile.
Obs.: Since the Media class is virtual, Media objects can't be instantiated.
Obs2.: video.cpp and photo.cpp were added to the Makefile

I-a. Polymorphism of Heritage allows generic treatment of derived classes. In C++ a pointer to the base class is able to call methods of the derived if the base class that changes in the virtual class is virtual. In Java aways calls the point method.


II.
    i. The object film mantains an internal copy of the table, meaning that it's copied from an external table. Once this is done, only the Object could modify it.

    ii. The getter of table returns a const int. This achives encapsulation.

    iii. The pointer to the table can be accessed only by the Object.

    iv. Tested and succeded.

III.

    i. All objects that have instantiated attributes with dynamic memory must have the delete specified to avoid loss of memory. So far only the class Film needs this treatent. The copy of an object can pose problems

    ii. Copying an object can pose problems when there are attributes dynamiccaly allocated since making a shallow copy and destroying taking into account (i) will result in an object whose pointer isn't a valid memory allocation. This must be solved by making deep copies of all such classes. As previously said in (i), only the class Film needs to be addressed by redefining the copying functions (done for Film class).

## Javaswing:

In java we could do List<Object> object = new ArrayList<Object>();
To allow only the Manager to create new Media, the constructor of these classes should be made private and the Manager class could be made a friendly class of Media and all it's descendets. This was not implemented since all previous tests in main() would have to be changed.
