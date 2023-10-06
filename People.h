#ifndef People_
#define People_
#include "Item.h"
#include <string>
using namespace std;

class People{
    protected:
        string name;
        Item* items = new Item[NULL];
        int maxCarry;
        int carryAmount = 0; 
    public:
        bool grabItem(Item product, Inventory storage){
            if (carryAmount < maxCarry){
                items[carryAmount] = product;
                carryAmount++
                return true;
                storage.removeItem(product);
            }
            return false;
        }
        int getcarryAmount(){return carryAmount;}
};
#endif