#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

#include "Inventory.h"
#include "Item.h"
#include "People.h"

class Customer : public People {
 protected:
  Item* items;

 public:
    Customer(){
        name = "";
        maxCarry = 0;
    }
    Customer(string name, int day){
        this->name = name;
        maxCarry = 2*day*0.5;
    }
};

#endif