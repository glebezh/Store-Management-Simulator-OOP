#ifndef CHOCOLATE_H
#define CHOCOLATE_H

#include <iostream>

#include "Item.h"

class Chocolate : public Item{
  private:
  public:
    Chocolate(): Item("Chocolate", 2.00, 1.75, false, 0){
    };
    ~Chocolate(){};

    bool determineExpiry() override{
      if (counter == 3){
        expired = true;
      };
      return expired;
  }
};

#endif