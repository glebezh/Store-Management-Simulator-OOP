#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;

#include <string>
#include <iostream>

#include "Dairy.h"
#include "Produce.h"
#include "Dry.h"

class Inventory{
    private:
        Dairy* dairy_products;
        Dry* dry_products;
        Produce* produce_products;
        double money;
    public:
        int getDairyItem(string name);
        int getDryItem(string name);
        int getProduceItem(string name);
        void removeItem(string name);
        void buyItem(string type, string amount);

        Inventory();
        Inventory();

};


#endif