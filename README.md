# INF224

Answers:

4. The Media class is set to a virtual type since we want to use polymorphism of heritage to generalize the usage of the play method. This method is thus virtual. We need to override the method in the inherited classes.
The method is declared at the header of each class so there is no need to modify makefile.
Obs.: Since the Media class is virtual, Media objects can't be instantiated.
Obs2.: video.cpp and photo.cpp were added to the Makefile

5. Polymorphism of Heritage allows generic treatment of derived classes. In C++ a pointer to the base class is able to call methods of the derived if the base class that changes in the virtual class is virtual. In Java aways calls the point method.


6.
    i. The object film mantains an internal copy of the table, meaning that it's copied from an external table. Once this is done, only the Object could modify it.

    ii. The getter of table returns a const int. This achives encapsulation.

    iii. The pointer to the table can be accessed only by the Object. 

    iv. Tested and succeded.