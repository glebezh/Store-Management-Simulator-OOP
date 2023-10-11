#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
 protected:
  string name;
  double sellPrice;
  double purchasePrice;
  bool hasExpiry;

 public:
  Item();
  Item(string _name, double _sellPrice, double _purchasePrice, bool _hasExpiry);
  virtual string getName() { return name; }   // Do we need virtual here?
  virtual double getsellPrice() { return sellPrice; }
  virtual double getpurchasePrice() { return purchasePrice; }
  virtual bool gethasExpiry() { return hasExpiry; }
  //~Item(){};
};

#endif