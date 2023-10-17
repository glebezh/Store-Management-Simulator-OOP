#ifndef MILK_H
#define MILK_H

#include "Item.h"

// Class containing information for Milk object
class Milk : public Item {
 private:
 public:
  Milk() : Item("Milk", 2, 1.5, false, 0){};
  ~Milk(){};

  bool determineExpiry() override {
    if (counter == 5) {
      expired = true;
    };
    counter = counter + 1;
    return expired;
  }
};

#endif