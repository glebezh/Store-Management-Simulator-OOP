#include <iostream>
#include "Inventory.h"
#include "Item.h"


using namespace std;


int main(void){

    Item item1("Apple", 2.0, 1.0, 0);
    Item item2("Banana",2.0, 1.0, 0);
    Item item3("Cabbage", 3.0, 2.0 ,0);

    Item* items[] = { &item1, &item2, &item3 };
    Inventory myInventory(items, 100.0);

    myInventory.getItems();
    myInventory.buyItem("Item1", 2);
    myInventory.removeItem("Item2");

    // Get the remaining money in the inventory
    double remainingMoney = myInventory.getMoney();
    std::cout << "Remaining money in the inventory: $" << remainingMoney << std::endl;

    return 0;
}
