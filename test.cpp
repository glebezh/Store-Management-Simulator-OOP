#include <iostream>

#include "Customer.h"
#include "Inventory.h"
#include "Random.h"

int main() {
  initRandom();
  srand(time(0));

  int dayCounter = 1;

  double totalMoney = 100;

  std::cout << "Money: " << totalMoney << std::endl;

  int numCustomers = generateRandom(1, 2 * dayCounter + 1);

  Inventory hold(totalMoney);

  hold.buyItemProduce();
  hold.showproduceItems();

  for (int i = 0; i < numCustomers; i++) {
    Customer customer;

    std::vector<std::string> items = {"Apple",   "Banana", "Carrot",
                                      "Biscuit", "Bread",  "Chocolate",
                                      "Cheese",  "Milk",   "Yoghurt"};
    customer.setDesiredItem1(items[generateRandom(0, items.size() - 1)]);
    customer.setDesiredItem2(items[generateRandom(0, items.size() - 1)]);
    customer.setDesiredItem3(items[generateRandom(0, items.size() - 1)]);

    customer.buyFromInventory1(hold);
    customer.buyFromInventory2(hold);
    customer.buyFromInventory3(hold);
    totalMoney = totalMoney + customer.getMoneySpent();

    std::cout << "Customer " << i + 1 << " bought " << customer.itemsBought()
              << " items" << std::endl;

    std::cout << "Money: " << totalMoney << std::endl;
  }

  return 0;
}