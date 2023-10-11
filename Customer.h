#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

#include "Inventory.h"
#include "Item.h"
#include "People.h"

class Customer: public People{
    protected:
        Item* items;
    public:
    Customer(){
        maxCarry = 0;
        items = new Item[maxCarry];
        name = NULL;
        }
    Customer(string name){
        maxCarry = 3 + (rand() %7);
        items = new Item[maxCarry];
        this->name = name;
    
    }
        void checkout(Item* cart, Inventory shop, Store store){
            double cartPrice = 0
            for (int i = 0; i<this->getcarryAmount(); i++){
                cartPrice = cartPrice + cart[i]*.getsellPrice();
            }
            shop.setMoney = shop.getMoney + cartPrice + 2*store.getRating();
        }
        ~Customer(){delete items[]}
};

#endif