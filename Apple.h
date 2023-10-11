#ifndef APPLE_H
#define APPLE_H

#include <iostream>

#include "Item.h"

class Apple : public Item{
  private:
    int counter;
    // need something else here?

  public:
    Apple(): Item("Apple", 1.00, 0.75, false){
      counter = 0;
    };
    ~Apple(){};

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