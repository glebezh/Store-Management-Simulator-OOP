#ifndef BANANA_H
#define BANANA_H

#include "Item.h"

// Class containing information for Banana object
class Banana : public Item {
 private:
 public:
  Banana() : Item("Banana", 1.25, 0.90, false, 0){};
  ~Banana(){};

  bool determineExpiry() override {
    if (counter == 3) {
      expired = true;
    };
    counter = counter + 1;
    return expired;
  }
};

#endif