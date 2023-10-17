#ifndef BISCUIT_H
#define BISCUIT_H

#include "Item.h"

// class containing information for Biscuit object
class Biscuit : public Item {
 private:
 public:
  Biscuit() : Item("Biscuit", 1.25, 0.90, false, 0){};
  ~Biscuit(){};

  bool determineExpiry() override {
    if (counter == 6) {
      expired = true;
    };
    counter = counter + 1;
    return expired;
  }
};

#endif