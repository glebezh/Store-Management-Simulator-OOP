#ifndef BISCUIT_H
#define BISCUIT_H

#include <iostream>

#include "Item.h"

class Biscuit : public Item {
 private:
  string name = "Biscuit";
  double sellPrice = 1.25;
  double purchasePrice = 0.90;
  bool hasExpiry = false;
  int counter = 0;

 public:
  Biscuit(){};
  ~Biscuit(){};
  virtual string getName() { return name; }
  virtual double getsellPrice() { return sellPrice; }
  virtual double getpurchasePrice() { return purchasePrice; }
  virtual bool gethasExpiry() {
    counter = counter + 1;
    if (counter == 6) {
      hasExpiry = true;
    };
    return hasExpiry;
  }
};

#endif