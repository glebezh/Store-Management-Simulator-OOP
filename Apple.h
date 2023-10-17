#ifndef APPLE_H
#define APPLE_H
// class containing information for Apple object
#include "Item.h"

class Apple : public Item {
 public:
  Apple() : Item("Apple", 1.00, 0.75, false, 0) {}
  ~Apple() {}

  bool determineExpiry() override {
    if (counter == 1) {
      expired = true;
    }
    counter = counter + 1;
    return expired;
  }
};

#endif
