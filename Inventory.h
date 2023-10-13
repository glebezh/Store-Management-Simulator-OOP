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
  std::vector<Item*> dairyItems;
  double money;
  int produceCounter = 0;
  int dryCounter = 0;
  int dairyCounter = 0;

 public:
  // Constructors
  Inventory();
  Inventory(double _money);
  // Methods/Functions
  void removeItem(string name);
  void buyItemProduce();
  void buyItemDry();
  void buyItemDairy();
  void showproduceItems();
  void showdryItems();
  void showdairyItems();

  void setMoney(double money_) { this->money = money_; };
  double getMoney() { return money; };

  int getProduceCounter() { return produceCounter; };
  int getDryCounter() { return dryCounter; };
  int getDairyCounter() { return dairyCounter; };

  std::vector<Item*> getProduceItems() { return produceItems; };
  std::vector<Item*> getDryItems() { return dryItems; };
  std::vector<Item*> getDairyItems() { return dairyItems; };

  int checkProduceExpiry();
  int checkDryExpiry();
  int checkDairyExpiry();

  
};

#endif