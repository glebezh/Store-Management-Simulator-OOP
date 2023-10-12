#ifndef APPLE_H
#define APPLE_H

#include <iostream>

#include "Item.h"

class Apple : public Item{
  private:
  public:
    Apple(): Item("Apple", 1.00, 0.75, false, 0){
    };
    ~Apple(){};

    bool determineExpiry() override{
      if (counter == 3){
        expired = true;
      };
      return expired;
  }

};

#endif