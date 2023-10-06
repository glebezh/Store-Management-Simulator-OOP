#ifndef CARROT_H
#define CARROT_H

#include <iostream>

#include "Produce.h"

class Carrot : public Produce {
 private:
  string name = "Carrot";
  double sellPrice = 1.50;
  double purchasePrice = 1.25;
  bool hasExpiry = false;
  int counter = 0;

 public:
  Carrot(){};
  ~Carrot(){};
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