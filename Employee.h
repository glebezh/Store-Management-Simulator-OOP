#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

#include "Inventory.h"
#include "Person.h"

class Employee : public Person {
 private:
  double wageCost;
  double tipCost;

 public:
  Employee(){};
  Employee(string _name):Person(_name){
     wageCost = 50;
     tipCost = 2;
  };
  void drawWage(Inventory shop){
    shop.setMoney(shop.getMoney() - wageCost - tipCost);
  }
};

#endif