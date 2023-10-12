#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;

#include <iostream>
#include <string>
#include <vector>

#include "Item.h"

class Inventory {
 private:
  std::vector<Item*> produceItems;
  std::vector<Item*> dryItems;
  double money;
  int produceCounter = 0;
  int dryCounter = 0;

 public:
  // Constructors
  Inventory();
  Inventory(double _money);

  // Methods/Functions
  void removeItem(string name);
  void buyItemProduce();
  void buyItemDry();
  void showproduceItems();
  void showdryItems();

  void setMoney(double money_) { this->money = money_; }
  double getMoney() { return money; }
};

#endif