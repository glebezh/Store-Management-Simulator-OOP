#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "People.h"
#include "Inventory.h"
#include "Store.h"

class Employee: public People{
    protected:
        double wageCost;
        double tipCost;
    public:
        Employee(){
            name = NULL
            wageCost = 0;
            tipcost = 0;
            maxCarry = NULL
            carryAmount = NULL
        }
        Employee(string name, Store shop){
            this->name = name;
            wageCost = 5 + (rand() %15);
            tipCost =  shop.getRating();
            maxCarry = NULL;
            carryAmount = NULL;
            }
        void drawWage(Inventory shop){
            shop.setMoney(shop.getMoney() - wageCost);
        }

};

#endif