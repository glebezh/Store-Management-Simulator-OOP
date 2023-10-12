#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

#include "Inventory.h"
#include "People.h"
#include "Inventory.h"
#include "Store.h"

class Employee: public People{
    protected:
        double wageCost;
        double tipCost;
    public:
        Employee(){
            name = "";
            wageCost = 0;
            tipCost = 0;
            maxCarry = 0;
            carryAmount = 0;
        }
        Employee(string name, Store shop){
            this->name = name;
            wageCost = 5 + (rand() %15);
            tipCost =  shop.getRating();
            maxCarry = 0;
            carryAmount = 0;
            }
        void drawWage(Inventory shop){
            shop.setMoney(shop.getMoney() - wageCost);
        }

};

#endif