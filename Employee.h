#ifndef Employee_
#define Employee_

#include <string>
#include "People.h"
#include "Inventory"

class Employee: public People{
    protected:
        double wageCost;
        double tipCost:
    private:
        void drawWage(Inventory shop){
            shop.setMoney(shop.getMoney() - wageCost);
        }

};

#endif