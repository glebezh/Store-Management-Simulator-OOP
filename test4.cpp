// This tests the functionality of the Employee Classes
// In this test the Employee Class which inherits from the People Classes will
// be tested

// To run this test use:
//  g++ test4.cpp Item.cpp Inventory.cpp -o "test4"
// ./test4

#ifndef TEST4_H
#define TEST4_H

#include <iostream>

#include "Employee.h"
#include "Inventory.h"
#include "Item.h"

int main() {
  // Creates a new Employee Class
  Employee classTest("Dummy1");

  // Tests the function which returns the employee's name
  std::cout << "Employee Name: " << classTest.getName() << std::endl;

  // Tests the function which returns the employee's cost
  std::cout << "Employee Cost: $" << classTest.getWage() << std::endl;

  // Tests the function which returns the employee's tip from customer
  std::cout << "Employee Tip: $" << classTest.getTip() << std::endl;

  return 0;
}

#endif