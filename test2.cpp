// This tests the functionality of the Inventory Class
// In this test Inventory Classes functions will be used to test how the items
// will be stored and accessed

// To run this test use:
//  g++ test2.cpp Inventory.cpp Item.cpp -o "test2"
// ./test2

#ifndef TEST2_H
#define TEST2_H

#include <iostream>

#include "Inventory.h"
#include "Item.h"

int main() {
  // Creates a new 'Inventory' Class with $100.15
  Inventory classTest(100.15);

  // Tests the function which shows the money within the Inventory
  std::cout << "Money: $" << classTest.getMoney() << std::endl;

  // Tests the function which purchases produce items (Apple, Banana and
  // Carrots)
  classTest.buyItemProduce();

  // Tests the function which prints out the array of produce items
  classTest.showproduceItems();

  // Tests whether the previous functions subtracted the correct amount of money
  // when purchased
  std::cout << "Money: $" << classTest.getMoney() << std::endl;

  // Tests whether the player can remove an item from the Inventory
  std::string itemRemove;
  std::cout << "Enter an item to remove (Needs correct spelling and "
               "capitilization --> Apple):"
            << std::endl;
  std::cin >> itemRemove;
  classTest.removeItem(itemRemove);

  // Tests to see if desired item is removed
  classTest.showproduceItems();

  // Assuming that the purchase and show items for dry items and dairy items
  // are coded similar this test passes
  return 0;
}

#endif