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
  Item(){};
  Item(string _name, double _sellPrice, double _purchasePrice, bool _hasExpiry);
  ~Item(){};
  virtual string getName() { return name; }
  virtual double getSellPrice() { return sellPrice; }
  virtual double getPurchasePrice() { return purchasePrice; }
  virtual bool getHasExpiry() { return hasExpiry; }
};

#endif