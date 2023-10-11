#ifndef BANANA_H
#define BANANA_H

#include <iostream>

#include "Item.h"

class Banana : public Item{
  private:
    int counter;
    // need something else here?

  public:
    Banana(): Item("Banana", 1.25, 0.90, false){
      counter = 0;
    };
    ~Banana(){};

    bool determineExpiry(){
      counter = counter + 1;
      if (counter == 3)
      {
        hasExpiry = true;
      };
      return hasExpiry;
    }
};

#endif