#ifndef PRODUCE_H
#define PRODUCE_H

#include "Item.h"

class Produce : public Item {
 private:
  string name;
  double sellPrice;
  double purchasePrice;
  bool hasExpiry;

 public:
  Produce(){};
  ~Produce(){};
  virtual string getName() { return name; }
  virtual double getsellPrice() { return sellPrice; }
  virtual double getpurchasePrice() { return purchasePrice; }
  virtual bool gethasExpiry() { return hasExpiry; }
};

#endif