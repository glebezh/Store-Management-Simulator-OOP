#ifndef MILK_H
#define MILK_H

#include "Item.h"

class Milk : public Item {
 private:
  string name = "Milk";
  double sellPrice = 2.25;
  double purchasePrice = 1.75;
  bool hasExpiry = false;
  int counter = 0;

 public:
  Milk(){};
  ~Milk(){};
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