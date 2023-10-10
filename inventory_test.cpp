#include <iostream>
#include "Inventory.h"
#include "Item.h"


using namespace std;


int main(void){


    const int array_size = 5;
    Item* itemsArray = new Item[array_size];

    itemsArray[0] = Item("Apple", 10.0, 5.0, true);
    itemsArray[1] = Item("Banana", 15.0, 7.0, false);
    itemsArray[2] = Item("Pear", 8.0, 4.0, true);
    itemsArray[3] = Item("Cabbage", 12.0, 6.0, false);
    itemsArray[4] = Item("Meat", 20.0, 10.0, true);

    Inventory myInventory(itemsArray, 100.0);

    myInventory.getItems(array_size);
    
    // Get the remaining money in the inventory
    double remainingMoney = myInventory.getMoney();
    std::cout << "Remaining money in the inventory: $" << remainingMoney << std::endl;

    return 0;
}
