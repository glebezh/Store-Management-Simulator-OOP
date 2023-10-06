#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

#include "Inventory.h"
#include "People.h"

class Employee : public People {
 protected:
  double wageCost;
  double tipCost;

 private:
  void drawWage(Inventory shop) { shop.setMoney(shop.getMoney() - wageCost); }
};

#endif