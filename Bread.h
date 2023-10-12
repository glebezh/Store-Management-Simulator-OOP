#ifndef BREAD_H
#define BREAD_H

#include <iostream>

#include "Item.h"

class Bread : public Item {
 private:
  double sellPrice = 1;
  double purchasePrice = 0.75;
  bool hasExpiry = true;
  int counter = 0;
  int expiry = 9;

 public:
  Bread() : Item("Bread", 1.25, 0.90, false) { counter = 0; };
  ~Bread(){};

  bool determineExpiry() {
    counter = counter + 1;
    if (counter == 7) {
      hasExpiry = true;
    };
    return hasExpiry;
  }
};

#endif