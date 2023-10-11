#ifndef YOGHURT_H
#define YOGHURT_H

#include "Item.h"

class Yoghurt : public Item {
 private:
  string name = "Yoghurt";
  double sellPrice = 2.00;
  double purchasePrice = 1.75;
  bool hasExpiry = false;
  int counter = 0;

 public:
  Yoghurt(){};
  ~Yoghurt(){};
  string getName() { return name; }
  double getsellPrice() { return sellPrice; }
  double getpurchasePrice() { return purchasePrice; }
  bool gethasExpiry() {
    counter = counter + 1;
    if (counter == 4) {
      hasExpiry = true;
    };
    return hasExpiry;
  }
};

#endif