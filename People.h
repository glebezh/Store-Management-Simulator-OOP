#ifndef People_
#define People_
#include <string>

#include "Item.h"
using namespace std;

class People {
 protected:
  string name;
  Item* items;
  int maxCarry;
  int carryAmount;

 public:
  People();
  People(string _name, Item* items, int _maxCarry, int _carryAmount){
    name = _name;
    items = nullptr;
    maxCarry = _maxCarry;
    carryAmount = _carryAmount;
  }
  
  bool grabItem(Item product) {
    if (carryAmount < maxCarry) {
      items[carryAmount] = product;
      carryAmount++; 
      return true;
    }
    return false;
  }
};

#endif