#include "Item.h"
#include <string>
#ifndef People_;
#define People_;
using namespace std;

class People{
    protected:
        string name;
        Item* items = new Item[NULL];
        int maxCarry;
        int carryAmount = 0; 
    public:
        bool grabItem(Item product){
            if (carryAmount < maxCarry){
                items[carryAmount] = product;
                carryAmount++
                return true;
            }
            return false;
        }
};
#endif;