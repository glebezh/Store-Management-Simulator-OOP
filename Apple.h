#ifndef APPLE_H
#define APPLE_H

#include <iostream>

#include "Produce.h"

class Apple : public Produce {
 private:
  string name = "Apple";
  double sellPrice = 1.00;
  double purchasePrice = 0.75;
  bool hasExpiry = false;
  int counter = 0;

 public:
  Apple(){};
  ~Apple(){};
  string getName() { return name; }
  double getsellPrice() { return sellPrice; }
  double getpurchasePrice() { return purchasePrice; }
  bool gethasExpiry() {
    counter = counter + 1;
    if (counter == 3) {
      hasExpiry = true;
    };
    return hasExpiry;
  }
};

#endif