#ifndef CHEESE_H
#define CHEESE_H

#include <iostream>

#include "Item.h"

class Cheese : public Item{
  private:
  public:
    Cheese(): Item("Cheese", 2.00, 1.75, false, 0){
    };
    ~Cheese(){};

    bool determineExpiry() override{
      if (counter == 3){
        expired = true;
      };
      return expired;
  }
};

#endif