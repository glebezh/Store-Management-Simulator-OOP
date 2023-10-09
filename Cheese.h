#ifndef CHEESE_H
#define CHEESE_H

#include "Item.h"

class Cheese : public Item {
 private:
  string name = "Cheese";
  double sellPrice = 2.00;
  double purchasePrice = 1.75;
  bool hasExpiry = false;
  int counter = 0;

 public:
  Cheese(){};
  ~Cheese(){};
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