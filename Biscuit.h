#ifndef BISCUIT_H
#define BISCUIT_H

#include <iostream>

#include "Item.h"

class Biscuit : public Item{
  private:
    int counter;
    // need something else here?

  public:
    Biscuit(): Item("Biscuit", 1.25, 0.90, false){
      counter = 0;
    };
    ~Biscuit(){};

    bool determineExpiry(){
      counter = counter + 1;
      if (counter == 6)
      {
        hasExpiry = true;
      };
      return hasExpiry;
    }
};

#endif