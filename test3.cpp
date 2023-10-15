// This tests the functionality of the Customer Classes
// In this test the Customer Class which inherits from the People Classes will
// be tested

// To run this test use:
//  g++ test3.cpp Item.cpp Inventory.cpp -o "test3"
// ./test3

#ifndef TEST3_H
#define TEST3_H

#include <iostream>

#include "Customer.h"
#include "Inventory.h"
#include "Item.h"

int main() {
  // Creates a new Inventory Class
  Inventory hold(100.15);

  hold.buyItemProduce();
  hold.showproduceItems();

  // Creates a new Customer Class
  Customer classTest("Dummy1");

  // Tests the function which returns the customer's name
  std::cout << "Customer Name: " << classTest.getName() << std::endl;

  // Tests the functions which sets items which the customer wishes to
  // purchase
  classTest.setDesiredItem1("Apple");
  classTest.setDesiredItem2("Banana");
  classTest.setDesiredItem3("Carrot");

  // Tests the functions which return items which the customer wishes to
  // purchase
  std::cout << "Item 1: " << classTest.getDesiredItem1() << std::endl;
  std::cout << "Item 2: " << classTest.getDesiredItem2() << std::endl;
  std::cout << "Item 3: " << classTest.getDesiredItem3() << std::endl;

  // Tests the function which allows the customer to buy from the inventory
  classTest.buyFromInventory1(hold);
  classTest.buyFromInventory2(hold);
  classTest.buyFromInventory3(hold);

  // Tests the function which returns the money spent by the customer
  std::cout << "Money Spent: $" << classTest.getMoneySpent() << std::endl;

  // Tests the function which returns the number of items bought
  std::cout << "Items Bought: " << classTest.itemsBought() << std::endl;

  // Assuming that the customter can interact with the inventory for dry items
  // and dairy items are coded similar this test passes

  return 0;
}

#endif