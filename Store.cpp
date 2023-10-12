#include "Store.h"

#include <iostream>

using namespace std;

Store::Store() {
  name = ' ';
  days = 0;
  rating = 0;
  inventory = nullptr;
  customers = nullptr;
  employees = nullptr;
}

Store::Store(string _name, int _days, Inventory* _inventory) {
  name = _name;
  days = _days;
  inventory = _inventory;
}

void Store::getInventory() {}

void Store::getCustomers() {}

void Store::getEmployees() {}

string Store::getName() { return name; }

int Store::getDays() { return days; }

double Store::getRating() { return rating; }
