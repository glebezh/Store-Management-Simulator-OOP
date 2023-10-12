#ifndef BISCUIT_H
#define BISCUIT_H

#include <iostream>

#include "Item.h"

class Biscuit : public Item{
  private:
    double sellPrice = 2.25;
    double purchasePrice = 1.50;
    bool hasExpiry = false;
    int counter = 0;
    

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