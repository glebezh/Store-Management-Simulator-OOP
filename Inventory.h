#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;

#include <iostream>
#include <string>

class Inventory {
 private:
  double money;

 public:
  int getDairyItem(string name);
  int getDryItem(string name);
  int getProduceItem(string name);
  void removeItem(string name);
  void buyItem(string type, string amount);
  void setMoney(double money_) { this->money = money_; }
  double getMoney() { return money; }
  Inventory();
  Inventory();
};

#endif