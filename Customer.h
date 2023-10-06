#ifndef Customer_
#define Customer_

#include <string>
#include "People.h"
#include "Inventory"
#include "Item.h"

class Customer: public People{
    protected:
        Item* items;
    public:
        void checkout(Item* cart, Inventory shop, Store store){
            double cartPrice = 0
            for (int i = 0; i<this->getcarryAmount(); i++){
                cartPrice = cartPrice + cart[i]*.getsellPrice();
            }
            shop.setMoney = shop.getMoney + cartPrice + 2*store.getRating();
        }
};

#endif