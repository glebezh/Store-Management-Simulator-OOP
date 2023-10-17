#ifndef YOGHURT_H
#define YOGHURT_H

#include "Item.h"

//Class containing information for Yoghurt object
class Yoghurt : public Item {
 private:
 public:
  Yoghurt() : Item("Yoghurt", 3, 2, false, 0){};
  ~Yoghurt(){};

  bool determineExpiry() override {
    if (counter == 4) {
      expired = true;
    };
    counter = counter + 1;
    return expired;
  }
};

#endif