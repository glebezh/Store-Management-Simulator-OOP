#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

// Abstract Class containing information for Item object
class Item {
 protected:
  // member variables, inherited by all other items
  string name;
  double sellPrice;
  double purchasePrice;
  bool expired;
  int counter;

 public:
  // constructors
  Item();
  Item(string _name, double _sellPrice, double _purchasePrice, bool _expired,
       int _counter);
  ~Item(){};
  //get and set functions
  string getName() { return name; }
  double getSellPrice() { return sellPrice; }
  double getPurchasePrice() { return purchasePrice; }
  bool getExpired() { return expired; }
  int getCounter() { return counter; }
  void setCounter(int _counter) { counter = _counter; }

  // Virtual bool function to check the expiry of items.
  virtual bool determineExpiry() {
    if (counter == 3) {
      expired = true;
    };
    counter = counter + 1;
    return expired;
  }
};

#endif