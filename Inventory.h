#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;

#include <string>
#include <iostream>

#include "Item.h"

class Inventory{
    private:
        Item* items;
        double money;
    public:
        //Constructors
        Inventory();
        Inventory(Item* _items, double _money);

        //Methods/Functions
        void removeItem(string name);
        void buyItem(string type, int amount);
        void getItems(int _size);

        void setMoney(double money_){
            this->money = money_; 
        };
        double getMoney(){return money;};
        
};


#endif