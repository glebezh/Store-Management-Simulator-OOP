#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "People.h"
#include "Inventory.h"

class Employee: public People{
    protected:
        double wageCost;
        double tipCost;
    private:
        void drawWage(Inventory shop){
            shop.setMoney(shop.getMoney() - wageCost);
        }

};

#endif