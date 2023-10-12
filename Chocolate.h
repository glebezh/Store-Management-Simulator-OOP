#ifndef CHOCOLATE_H
#define CHOCOLATE_H

#include <iostream>

#include "Item.h"

class Chocolate : public Item {
 private:
  string name = "Chocolate";
  double sellPrice = 2.25;
  double purchasePrice = 1.50;
  bool hasExpiry = false;
  int counter = 0;

 public:
  Chocolate(){};
  ~Chocolate(){};
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