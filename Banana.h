#ifndef BANANA_H
#define BANANA_H

#include <iostream>

#include "Item.h"

class Banana : public Item {
 private:
  double sellPrice = 2.25;
  double purchasePrice = 1.50;
  bool hasExpiry = true;
  int counter = 0;
  int expiry = 4;

 public:
  Banana() : Item("Banana", 1.25, 0.90, false) { counter = 0; };
  ~Banana(){};

  bool determineExpiry() {
    counter = counter + 1;
    if (counter == 3) {
      hasExpiry = true;
    };
    return hasExpiry;
  }
};

#endif