#include <iostream>

#include "Inventory.h"

int main() {
  Inventory hold(100);
  hold.buyItemProduce();
  hold.showproduceItems();
  hold.removeItem("Apple");
  hold.showproduceItems();
  hold.buyItemProduce();
  hold.showproduceItems();
  return 0;
}