#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

#include "Inventory.h"
#include "Person.h"

using namespace std;

class Employee : public Person {
 private:
  double wageCost;
  double tipCost;

 public:
  Employee(){};
  Employee(string _name):Person(_name){
     wageCost = generateRandom(2,6);
     tipCost = generateRandom(0,3);
  };
  void drawWage(Inventory& inventory){
    inventory.setMoney(inventory.getMoney() - wageCost + tipCost);
  }

  double getwageCost(){return wageCost;};
  double gettipCost(){return tipCost;}





};

#endif