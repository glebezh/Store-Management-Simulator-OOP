#ifndef CHEESE_H
#define CHEESE_H

#include <iostream>

#include "Item.h"

class Cheese : public Item{
  private:
    double sellPrice = 2.25;
    double purchasePrice = 1.50;
    bool hasExpiry = true;
    int counter = 0;
    int expiry = 10;

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