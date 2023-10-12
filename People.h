#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>

#include "Item.h"

using namespace std;

class Person {
  protected:
    string name;
  public:
    string getName(){return name;};


};

#endif