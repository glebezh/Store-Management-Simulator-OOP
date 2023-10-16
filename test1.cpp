// This tests the functionality of the Item Classes
// In this test the Apple Class which inherits from the Item Classes will be
// tested

// To run this test use:
//  g++ test1.cpp Item.cpp -o "test1"
// ./test1

#ifndef TEST1_H
#define TEST1_H

#include <iostream>

#include "Apple.h"
#include "Item.h"

int main() {
  // Creates a new 'Apple' Class
  Apple classTest;

  // Tests the functions within the 'Apple' Class to visualize the Class's
  // properties
  //(Name, Purchase Price, Sell Price and Expiry)
  std::cout << "Name: " << classTest.getName() << std::endl;
  std::cout << "Purchase Price: " << classTest.getPurchasePrice() << std::endl;
  std::cout << "Sell Price: " << classTest.getSellPrice() << std::endl;
  std::cout << "Expired: " << classTest.getExpired() << std::endl;
  return 0;
}

#endif