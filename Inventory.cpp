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

void Inventory::removeItem(string name) {
  for (int i = 0; i < produceCounter; i++) {
    if (produceItems[i]->getName() == name) {
      std::cout << name << " was removed" << std::endl;
      delete produceItems[i];
      produceItems[i] = nullptr;
      std::swap(produceItems[i], produceItems[produceCounter - 1]);
      produceItems.pop_back();
      produceCounter--;
      std::cout << "Enter 0 to continue" << std::endl;
      std::cin >> placeholder;
      break;
    }
  }
  for (int i = 0; i < dryCounter; i++) {
    if (dryItems[i]->getName() == name) {
      std::cout << name << " was removed" << std::endl;
      delete dryItems[i];
      dryItems[i] = nullptr;
      std::swap(dryItems[i], dryItems[dryCounter - 1]);
      dryItems.pop_back();
      dryCounter--;
      std::cout << "Enter 0 to continue" << std::endl;
      std::cin >> placeholder;
      break;
    }
  }
  for (int i = 0; i < dairyCounter; i++) {
    if (dairyItems[i]->getName() == name) {
      std::cout << name << " was removed" << std::endl;
      delete dairyItems[i];
      dairyItems[i] = nullptr;
      std::swap(dairyItems[i], dairyItems[dairyCounter - 1]);
      dairyItems.pop_back();
      dairyCounter--;
      std::cout << "Enter 0 to continue" << std::endl;
      std::cin >> placeholder;
      break;
    }
  }
}

void Inventory::buyItemProduce() {
  int counter = 0;
  int choice = 1;
  int option = 0;
  system("clear");
  while (choice == 1 && money >= 0) {
    if (produceCounter == 5) {
      std::cout << "Maximum Capacity for Produce has been reached."
                << std::endl;
      std::cout << "Enter 0 to continue" << std::endl;
      std::cin >> choice;
      break;
    }
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
          //cost = 0.75;
          newItem = new Apple;
        } else if (option == 2) {
          //cost = 0.90;
          newItem = new Banana;
        } else if (option == 3) {
          //cost = 1.25;
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
          //money -= cost; 
          money -= newItem->getPurchasePrice();
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
    if (dryCounter == 5) {
      std::cout << "Maximum Capacity for Dry has been reached." << std::endl;
      std::cout << "Enter 0 to continue" << std::endl;
      std::cin >> choice;
      break;
    }
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

void Inventory::buyItemDairy() {
  int choice = 1;
  int option = 0;
  system("clear");
  while (choice == 1 && money >= 0) {
    if (dairyCounter == 5) {
      std::cout << "Maximum Capacity for Dairy has been reached." << std::endl;
      std::cout << "Enter 0 to continue" << std::endl;
      std::cin >> choice;
      break;
    }
    std::cout << "Money Remaining: $" << money << std::endl;
    std::cout << "Do you wish to buy Dairy (Cheese, Milk or Yoghurt)?"
              << std::endl;
    std::cout << "Enter 1 for Yes or 0 for No" << std::endl;
    std::cin >> choice;
    while ((choice != 1) && (choice != 0)) {
      std::cout << "Please enter a valid number" << std::endl;
      std::cout << "Money Remaining: $" << money << std::endl;
      std::cout << "Do you wish to buy Dairy (Cheese, Milk or Yoghurt)?"
                << std::endl;
      std::cout << "Enter 1 for Yes or 0 for No" << std::endl;
      std::cin >> choice;
    }
    if (choice == 1) {
      system("clear");
      std::cout << "Money Remaining: $" << money << std::endl;
      std::cout << "Do you wish to buy Cheese (1)(-$1.75)(+$2.00), Milk "
                   "(2)(-$1.75)(+$2.25) or "
                   "Yoghurt (3)(-$1.50)(+$2.50)?"
                << std::endl;
      std::cin >> option;
      if ((option != 1) && (option != 2) && (option != 3)) {
        system("clear");
        std::cout << "Money Remaining: $" << money << std::endl;
        std::cout << "Please enter a valid number" << std::endl;
        std::cout << "Do you wish to buy Cheese (1)(-$1.75)(+$2.00), Milk "
                     "(2)(-$1.75)(+$2.25) or "
                     "Yoghurt (3)(-$1.50)(+$2.50)?"
                  << std::endl;
        std::cin >> option;
      }
      if (option >= 1 && option <= 3) {
        double cost = 0;
        Item* newItem = nullptr;
        if (option == 1) {
          cost = 1.75;
          newItem = new Cheese;
        } else if (option == 2) {
          cost = 1.75;
          newItem = new Milk;
        } else if (option == 3) {
          cost = 1.50;
          newItem = new Yoghurt;
        }

        if (money - cost < 0) {
          system("clear");
          std::cout << "You don't have enough money for this item."
                    << std::endl;
          delete newItem;
        } else {
          system("clear");
          std::cout << newItem->getName() << " was added" << std::endl;
          dairyItems.push_back(newItem);
          money -= cost;
          dairyCounter++;
        }
      }
    }
  }

  std::cout << "Items Bought:" << std::endl;
  for (int i = 0; i < dairyCounter; i++) {
    std::cout << dairyItems[i]->getName() << std::endl;
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

void Inventory::showdairyItems() {
  std::cout << "Dairy Items:" << std::endl;
  for (int i = 0; i < dairyCounter; i++) {
    std::cout << dairyItems[i]->getName() << std::endl;
  }
}
