#ifndef CHOCOLATE_H
#define CHOCOLATE_H

#include <iostream>

#include "Item.h"
// class containing information for Chocolate object

class Chocolate : public Item{
  private:
  public:
    Chocolate(): Item("Chocolate", 2.00, 1.75, 0, 3){
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