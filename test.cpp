#include <iostream>

#include "Inventory.h"

int main() {
  Inventory hold(100);
  hold.buyItemProduce();
  hold.buyItemDry();
  hold.showproduceItems();
  hold.showdryItems();
  return 0;
}