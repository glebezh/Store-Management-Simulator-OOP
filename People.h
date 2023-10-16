#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>

#include "Item.h"
// class containing information for People object

using namespace std;

class Person {
  protected:
    string name;
  public:
    string getName(){return name;};


};

#endif