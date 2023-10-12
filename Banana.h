#ifndef BANANA_H
#define BANANA_H

#include <iostream>

#include "Item.h"

class Banana : public Item{
  private:
  public:
    Banana(): Item("Banana", 1.25, 0.90, false, 0){
    };
    ~Banana(){};

    bool determineExpiry() override{
      if (counter == 3){
        expired = true;
      };
      return expired;
  }
};

#endif