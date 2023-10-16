#ifndef BREAD_H
#define BREAD_H

#include <iostream>

#include "Item.h"
// class containing information for Bread object
class Bread : public Item{
  private:
  public:
    Bread(): Item("Bread", 1.25, 0.90, false, 0){
    };
    ~Bread(){};

    bool determineExpiry() override{
      if (counter == 7){
        expired = true;
      };
      return expired;
  }
};

#endif