#include "Item.h"

Item::Item(){
    name = ' ';
    sellPrice = 0;
    purchasePrice = 0;
    hasExpiry = 0;
}

Item::Item(string _name, double _sellPrice, double _purchasePrice, bool _hasExpiry){
    name = _name;
    sellPrice = _sellPrice;
    purchasePrice = _purchasePrice;
    hasExpiry = _hasExpiry;
}