#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

#include "Inventory.h"
#include "Item.h"
#include "People.h"

class Customer : public People {
 protected:
  Item* items;

 public:
};

#endif