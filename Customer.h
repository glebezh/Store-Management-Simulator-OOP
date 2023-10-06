#ifndef Customer_
#define Customer_

#include <string>

#include "Inventory.h"
#include "Item.h"
#include "People.h"

class Customer : public People {
 protected:
  Item* items;

 public:
  // functions
};

#endif