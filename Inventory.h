#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;

#include <iostream>
#include <string>
#include <vector>

#include "Item.h"

class Inventory {
 private:
  std::vector<Item*> items;
  double money;

 public:
  // Constructors
  Inventory(){
    money = NULL;
  }
  Inventory(double _money){
    money = _money;
  }

  // Methods/Functions
  void removeItem(string name);
  void buyItemProduce();
  void buyItemDry();
  void getItems();

  void setMoney(double money_) { this->money = money_; }
  double getMoney() { return money; }
};

#endif