// This tests the functionality of the save file

// To run this test use:
//  g++ test5.cpp load_save.cpp -o "test5"
// ./test5

#ifndef TEST5_H
#define TEST5_H

#include <iostream>

#include "Load.h"

int main() {
  // Creates a new load class
  Load load;

  // Tests the functions to access elements of the save file
  std::cout << "Store Name: " << load.getName() << std::endl;
  std::cout << "Store Money: $" << load.getMoney() << std::endl;
  std::cout << "Store Rating: " << load.getRating() << std::endl;
  std::cout << "Number of Produce Items: " << load.getProduceItems()
            << std::endl;
  std::cout << "Number of Apples " << load.getApple() << std::endl;
  std::cout << "Number of Bananas " << load.getBanana() << std::endl;
  std::cout << "Number of Carrot " << load.getCarrot() << std::endl;

  // Assuming the functions to access the dry items and dairy items are coded
  // similarly then this passes
  return 0;
}

#endif