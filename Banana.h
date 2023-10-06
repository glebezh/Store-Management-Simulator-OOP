#ifndef BANANA_H
#define BANANA_H

#include <iostream>

#include "Produce.h"

class Banana : public Produce {
 private:
  string name = "Apple";
  double sellPrice = 1.25;
  double purchasePrice = 0.90;
  bool hasExpiry = false;
  int counter = 0;

 public:
  Banana(){};
  ~Banana(){};
  virtual string getName() { return name; }
  virtual double getsellPrice() { return sellPrice; }
  virtual double getpurchasePrice() { return purchasePrice; }
  virtual bool gethasExpiry() {
    counter = counter + 1;
    if (counter == 3) {
      hasExpiry = true;
    };
    return hasExpiry;
  }
};

#endif