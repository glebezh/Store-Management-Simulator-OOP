#ifndef YOGHURT_H
#define YOGHURT_H

#include <iostream>

#include "Item.h"

class Yoghurt : public Item{
  private:
  public:
    Yoghurt(): Item("Yoghurt", 3, 2, false, 0){
    };
    ~Yoghurt(){};

    bool determineExpiry() override{
      if (counter == 4){
        expired = true;
      };
      return expired;
  }
};

#endif