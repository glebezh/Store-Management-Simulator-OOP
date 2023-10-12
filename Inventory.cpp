#include "Inventory.h"

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
          produceItems.push_back(newItem);
          money -= cost;
          produceCounter++;
        }
      }
    }
  }

  std::cout << "Items Bought:" << std::endl;
  for (int i = 0; i < produceCounter; i++) {
    std::cout << produceItems[i]->getName() << std::endl;
  }

  std::cout << "Money Remaining: $" << money << std::endl;
}

void Inventory::buyItemDry() {
  int choice = 1;
  int option = 0;
  system("clear");
  while (choice == 1 && money >= 0) {
    std::cout << "Money Remaining: $" << money << std::endl;
    std::cout << "Do you wish to buy Dry (Biscuit, Bread or Chocolate)?"
              << std::endl;
    std::cout << "Enter 1 for Yes or 0 for No" << std::endl;
    std::cin >> choice;
    while ((choice != 1) && (choice != 0)) {
      std::cout << "Please enter a valid number" << std::endl;
      std::cout << "Money Remaining: $" << money << std::endl;
      std::cout << "Do you wish to buy Dry (Biscuit, Bread or Chocolate)?"
                << std::endl;
      std::cout << "Enter 1 for Yes or 0 for No" << std::endl;
      std::cin >> choice;
    }
    if (choice == 1) {
      system("clear");
      std::cout << "Money Remaining: $" << money << std::endl;
      std::cout << "Do you wish to buy Biscuit (1)(-$0.90)(+$1.25), Bread "
                   "(2)(-$0.90)(+$1.25) or "
                   "Chocolate (3)(-$1.50)(+$2.25)?"
                << std::endl;
      std::cin >> option;
      if ((option != 1) && (option != 2) && (option != 3)) {
        system("clear");
        std::cout << "Money Remaining: $" << money << std::endl;
        std::cout << "Please enter a valid number" << std::endl;
        std::cout << "Do you wish to buy Biscuit (1)(-$0.90)(+$1.25), Bread "
                     "(2)(-$0.90)(+$1.25) or "
                     "Chocolate (3)(-$1.50)(+$2.25)?"
                  << std::endl;
        std::cin >> option;
      }
      if (option >= 1 && option <= 3) {
        double cost = 0;
        Item* newItem = nullptr;
        if (option == 1) {
          cost = 0.90;
          newItem = new Biscuit;
        } else if (option == 2) {
          cost = 0.90;
          newItem = new Bread;
        } else if (option == 3) {
          cost = 1.50;
          newItem = new Chocolate;
        }

        if (money - cost < 0) {
          system("clear");
          std::cout << "You don't have enough money for this item."
                    << std::endl;
          delete newItem;
        } else {
          system("clear");
          std::cout << newItem->getName() << " was added" << std::endl;
          dryItems.push_back(newItem);
          money -= cost;
          dryCounter++;
        }
      }
    }
  }

  std::cout << "Items Bought:" << std::endl;
  for (int i = 0; i < dryCounter; i++) {
    std::cout << dryItems[i]->getName() << std::endl;
  }

  std::cout << "Money Remaining: $" << money << std::endl;
}

void Inventory::showproduceItems() {
  std::cout << "Produce Items:" << std::endl;
  for (int i = 0; i < produceCounter; i++) {
    std::cout << produceItems[i]->getName() << std::endl;
  }
}

void Inventory::showdryItems() {
  std::cout << "Dry Items:" << std::endl;
  for (int i = 0; i < dryCounter; i++) {
    std::cout << dryItems[i]->getName() << std::endl;
  }
}
