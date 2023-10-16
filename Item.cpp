#include "Item.h"
//item member functions
Item::Item() {
  name = ' ';
  sellPrice = 0;
  purchasePrice = 0;
  expired = 0;
  counter = 0;
}

Item::Item(string _name, double _sellPrice, double _purchasePrice,
           bool _expired, int _counter) {
  name = _name;
  sellPrice = _sellPrice;
  purchasePrice = _purchasePrice;
  expired = _expired;
  _counter = counter;
}