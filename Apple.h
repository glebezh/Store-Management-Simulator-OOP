#ifndef APPLE_H
#define APPLE_H

#include "Item.h"

// Class containing information for Apple object
class Apple : public Item {
 private:
 public:
  Apple() : Item("Apple", 1.00, 0.75, false, 0) {}
  ~Apple() {}

  bool determineExpiry() override {
    if (counter == 4) {
      expired = true;
    }
    counter = counter + 1;
    return expired;
  }
};

#endif
