#ifndef STORE_H
#define STORE_H

using namespace std;

#include <iostream>
#include <string>

#include "Customer.h"
#include "Employee.h"
#include "Inventory.h"

class Store {
 protected:
  string name;
  int days;
  double rating;
  Customer* customers;
  Inventory* inventory;
  Employee* employees;

 public:
  // Constructors
  Store();
  Store(string _name, int _days, Inventory* _inventory);

  // Methods/Functions
  void getInventory();
  void getCustomers();
  void getEmployees();
  string getName();
  int getDays();
  double getRating();
};

#endif
