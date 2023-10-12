#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
 protected:
  string name;
  double sellPrice;
  double purchasePrice;
  bool expired;
  int counter;

 public:
  Item(){};
  Item(string _name, double _sellPrice, double _purchasePrice, bool _expired, int _counter);
  ~Item(){};
  string getName() { return name; }
  double getSellPrice() { return sellPrice; }
  double getPurchasePrice() { return purchasePrice; }
  bool getExpired() { return expired; }
  virtual bool determineExpiry(){
      if (counter == 3){
        expired = true;
      };
      return expired;
  }

};

#endif