#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

// class containing information for Person object
class Person {
  protected:
    string name;
  public:
    // Constructors
    Person(){};
    Person(string _name){name=_name;};
    // Methods/functions
    string getName(){return name;}
};

#endif