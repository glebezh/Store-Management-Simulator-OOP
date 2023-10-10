#ifndef CHEESE_H
#define CHEESE_H

#include <iostream>

#include "Item.h"

class Cheese : public Item{
  private:
    int counter;
    // need something else here?

  public:
    Cheese(): Item("Cheese", 2.00, 1.75, false){
      counter = 0;
    };
    ~Cheese(){};

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