#include "Inventory.h"
#include <iostream>

#include <iostream>

#include "Apple.h"
#include "Banana.h"
#include "Biscuit.h"
#include "Bread.h"
#include "Carrot.h"
#include "Cheese.h"
#include "Chocolate.h"
#include "Item.h"
#include "Milk.h"
#include "Yoghurt.h"

Inventory::Inventory() { money = 0; }

Inventory::Inventory(double _money) { money = _money; }

void Inventory::removeItem(string name) {}

void Inventory::buyItemProduce() {
  int counter = 0;
  int choice = 1;
  int option = 0;
  system("clear");
  while (choice == 1 && money >= 0) {
    std::cout << "Money Remaining: $" << money << std::endl;
    std::cout << "Do you wish to buy Produce (Apples, Bananas or Carrots)?"
              << std::endl;
    std::cout << "Enter 1 for Yes or 0 for No" << std::endl;
    std::cin >> choice;
    while ((choice != 1) && (choice != 0)) {
      std::cout << "Please enter a valid number" << std::endl;
      std::cout << "Money Remaining: $" << money << std::endl;
      std::cout << "Do you wish to buy Produce (Apples, Bananas or Carrots)?"
                << std::endl;
      std::cout << "Enter 1 for Yes or 0 for No" << std::endl;
      std::cin >> choice;
    }
    if (choice == 1) {
      system("clear");
      std::cout << "Money Remaining: $" << money << std::endl;
      std::cout << "Do you wish to buy Apples (1)(-$0.75)(+$1.00), Bananas "
                   "(2)(-$0.90)(+$1.25) or "
                   "Carrots (3)(-$1.25)(+$1.50)?"
                << std::endl;
      std::cin >> option;
      if ((option != 1) && (option != 2) && (option != 3)) {
        system("clear");
        std::cout << "Money Remaining: $" << money << std::endl;
        std::cout << "Please enter a valid number" << std::endl;
        std::cout << "Do you wish to buy Apples (1)(-$0.75)(+$1.00), Bananas "
                     "(2)(-$0.90)(+$1.25) or "
                     "Carrots (3)(-$1.25)(+$1.50)?"
                  << std::endl;
        std::cin >> option;
      }
      if (option >= 1 && option <= 3) {
        double cost = 0;
        Item* newItem = nullptr;
        if (option == 1) {
          cost = 0.75;
          newItem = new Apple;
        } else if (option == 2) {
          cost = 0.90;
          newItem = new Banana;
        } else if (option == 3) {
          cost = 1.25;
          newItem = new Carrot;
        }

        if (money - cost < 0) {
          system("clear");
          std::cout << "You don't have enough money for this item."
                    << std::endl;
          delete newItem;
        } else {
          system("clear");
          std::cout << newItem->getName() << " was added" << std::endl;
          items.push_back(newItem);
          money -= cost;
          counter++;
        }
        delete newItem;
      }
    }
  }

  std::cout << "Items Bought:" << std::endl;
  for (int i = 0; i < counter; i++) {
    std::cout << items[i]->getName() << std::endl;
  }

  std::cout << "Money Remaining: $" << money << std::endl;

}



// void Inventory::buyItem(string type, int amount){
    

// }

// void Inventory::getItems(){
//     for (int i = 0; i < items.size(); i++){
//         std::cout << items[i].getName()<< std::endl;
//     }
// }
