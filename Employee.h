#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

#include "Inventory.h"
#include "People.h"

class Employee : public People {
 protected:
  double wageCost = 50;
  double tipCost = 2;

 private:
  Employee(string Ename) { name = Ename; };
  Employee(); 
  void drawWage(Inventory shop) {
    shop.setMoney(shop.getMoney() - wageCost);
  }
};

#endif