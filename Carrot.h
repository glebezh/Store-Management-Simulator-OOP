#ifndef CARROT_H
#define CARROT_H

#include <iostream>

#include "Item.h"

class Carrot : public Item{
  private:
    int counter;
    // need something else here?

  public:
    Carrot(): Item("Carrot", 1.5, 1.25, false){
      counter = 0;
    };
    ~Carrot(){};

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