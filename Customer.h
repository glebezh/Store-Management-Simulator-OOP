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
        //functions
};

#endif