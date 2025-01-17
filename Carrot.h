#ifndef CARROT_H
#define CARROT_H

#include "Item.h"

// class containing information for Carrot object
class Carrot : public Item {
 private:
 public:
  Carrot() : Item("Carrot", 1.5, 1.25, false, 0){};
  ~Carrot(){};

  bool determineExpiry() override {
    if (counter == 4) {
      expired = true;
    };
    counter = counter + 1;
    return expired;
  }
};

#endif