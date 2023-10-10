#include "Inventory.h"
#include <iostream>


Inventory::Inventory(){
    items = nullptr;
    money = 0;
}

Inventory::Inventory(Item* _items, double _money){
    items = _items;
    money = _money;
}

void Inventory::removeItem(string name){
    
}


void Inventory::buyItem(string type, int amount){
    

}

void Inventory::getItems(int _size){
    for (int i = 0; i < _size; i++){
        std::cout << items[i].getName()<< std::endl;
    }
}
