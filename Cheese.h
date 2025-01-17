#ifndef CHEESE_H
#define CHEESE_H

#include "Item.h"

// class containing information for Cheese object
class Cheese : public Item {
 private:
 public:
  Cheese() : Item("Cheese", 2.00, 1.75, false, 0){};
  ~Cheese(){};

  bool determineExpiry() override {
    if (counter == 3) {
      expired = true;
    };
    counter = counter + 1;
    return expired;
  }
};

#endif