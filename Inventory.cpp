#include "Inventory.h"


Inventory::Inventory(){
    items = nullptr;
    money = 0;
}

Inventory::Inventory(Item *_items, double _money){
    items = _items;
    money = _money;
}

void Inventory::removeItem(string name){
    
}

void Inventory::buyItem(string type, int amount){

}
