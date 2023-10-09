#ifndef BREAD_H
#define BREAD_H

#include <iostream>

#include "Item.h"

class Bread : public Item {
 private:
  string name = "Bread";
  double sellPrice = 1.25;
  double purchasePrice = 0.90;
  bool hasExpiry = false;
  int counter = 0;

 public:
  Bread(){};
  ~Bread(){};
  virtual string getName() { return name; }
  virtual double getsellPrice() { return sellPrice; }
  virtual double getpurchasePrice() { return purchasePrice; }
  virtual bool gethasExpiry() {
    counter = counter + 1;
    if (counter == 7) {
      hasExpiry = true;
    };
    return hasExpiry;
  }
};

#endif