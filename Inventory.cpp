#include "Inventory.h"

#include <iostream>

#include "Apple.h"
#include "Banana.h"
#include "Biscuit.h"
#include "Bread.h"
#include "Carrot.h"
#include "Cheese.h"
#include "Chocolate.h"
#include "Employee.h"
#include "Item.h"
#include "Milk.h"
#include "Yoghurt.h"

Inventory::Inventory() { money = 0; }

Inventory::Inventory(double _money) { money = _money; }

void Inventory::removeItem(string name) {
  for (int i = 0; i < produceCounter; i++) {
    if (produceItems[i]->getName() == name) {
      delete produceItems[i];
      produceItems[i] = nullptr;
      std::swap(produceItems[i], produceItems[produceCounter - 1]);
      produceItems.pop_back();
      produceCounter--;
      break;
    }
  }

  for (int i = 0; i < dryCounter; i++) {
    if (dryItems[i]->getName() == name) {
      delete dryItems[i];
      dryItems[i] = nullptr;
      std::swap(dryItems[i], dryItems[dryCounter - 1]);
      dryItems.pop_back();
      dryCounter--;
      break;
    }
  }

  for (int i = 0; i < dairyCounter; i++) {
    if (dairyItems[i]->getName() == name) {
      delete dairyItems[i];
      dairyItems[i] = nullptr;
      std::swap(dairyItems[i], dairyItems[dairyCounter - 1]);
      dairyItems.pop_back();
      dairyCounter--;
      break;
    }
  }
}

void Inventory::buyItemProduce() {
  int choice = 1;
  int option = 0;
  while (choice == 1 && money >= 0) {
    if (produceCounter == 1000) {
      std::cout << "Maximum Capacity for Produce has been reached."
                << std::endl;
      std::cout << "Enter 0 to continue" << std::endl;
      std::cin >> choice;
      break;
    }
    std::cout << "Money Remaining: $" << money << std::endl;
    std::cout << "Do you wish to buy Produce (Apples, Bananas or Carrots)?"
              << std::endl;
    std::cout << "Enter 1 for Yes or 0 for No." << std::endl;
    std::cin >> choice;
    while ((choice != 1) && (choice != 0)) {
      std::cout << "Please enter a valid number" << std::endl;
      std::cout << "Money Remaining: $" << money << std::endl;
      std::cout << "Do you wish to buy Produce (Apples, Bananas or Carrots)?"
                << std::endl;
      std::cout << "Enter 1 for Yes or 0 for No." << std::endl;
      std::cin >> choice;
      std::cout << "\n";
    }
    if (choice == 1) {
      std::cout << "Money Remaining: $" << money << std::endl;
      std::cout << "Which produce item would you like to buy? \n\n (1) Apples "
                   "(-$0.75)(+$1.00), \n (2) Bananas "
                   "(-$0.90)(+$1.25)\n (3) Carrots (-$1.25)(+$1.50)?"
                << std::endl;
      std::cout << std::endl;
      std::cout << "Produce Number: ";
      std::cin >> option;
      if ((option != 1) && (option != 2) && (option != 3)) {
        std::cout << "Money Remaining: $" << money << std::endl;
        std::cout << "Please enter a valid number" << std::endl;
        std::cout << "Do you wish to buy Apples (1)(-$0.75)(+$1.00), Bananas "
                     "(2)(-$0.90)(+$1.25) or "
                     "Carrots (3)(-$1.25)(+$1.50)?"
                  << std::endl;
        option = 0;
        std::cin >> option;
      }
      if (option >= 1 && option <= 3) {
        Item* newItem = nullptr;
        if (option == 1) {
          newItem = new Apple;
        } else if (option == 2) {
          newItem = new Banana;
        } else if (option == 3) {
          newItem = new Carrot;
        }

        if (money - newItem->getPurchasePrice() < 0) {
          std::cout << "You don't have enough money for this item."
                    << std::endl;
          delete newItem;
        } else {
          std::cout << newItem->getName() << " was added to the inventory."
                    << std::endl;
          std::cout << "\n";
          produceItems.push_back(newItem);
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
  std::cout << " " << std::endl;
}

void Inventory::buyItemDry() {
  int choice = 1;
  int option = 0;
  while (choice == 1 && money >= 0) {
    if (dryCounter == 1000) {
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
      std::cout << "Money Remaining: $" << money << std::endl;
      std::cout << "Which dry item would you like to buy? \n\n (1) Biscuit "
                   "(-$0.90)(+$1.25), \n (2) Bread "
                   "(-$0.90)(+$1.25)\n (3) Chocolate (-$1.50)(+$2.25)?"
                << std::endl;
      std::cout << std::endl;
      std::cout << "Dry Number: ";
      std::cin >> option;
      if ((option != 1) && (option != 2) && (option != 3)) {
        std::cout << "Money Remaining: $" << money << std::endl;
        std::cout << "Please enter a valid number" << std::endl;
        std::cout << "Which dry item would you like to buy? \n\n (1) Biscuit "
                     "(-$0.90)(+$1.25), \n (2) Bread "
                     "(-$0.90)(+$1.25)\n (3) Chocolate (-$1.50)(+$2.25)?"
                  << std::endl;
        std::cout << std::endl;
        std::cin >> option;
      }
      if (option >= 1 && option <= 3) {
        Item* newItem = nullptr;
        if (option == 1) {
          newItem = new Biscuit;
        } else if (option == 2) {
          newItem = new Bread;
        } else if (option == 3) {
          newItem = new Chocolate;
        }

        if (money - newItem->getPurchasePrice() < 0) {
          std::cout << "You don't have enough money for this item."
                    << std::endl;
          delete newItem;
        } else {
          std::cout << newItem->getName() << " was added" << std::endl;
          dryItems.push_back(newItem);
          money -= newItem->getPurchasePrice();
          dryCounter++;
        }
      }
    }
  }

  std::cout << "Items Bought:" << std::endl;
  for (int i = 0; i < dryCounter; i++) {
    std::cout << dryItems[i]->getName() << std::endl;
  }
  std::cout << " " << std::endl;
}

void Inventory::buyItemDairy() {
  int choice = 1;
  int option = 0;
  while (choice == 1 && money >= 0) {
    if (dairyCounter == 1000) {
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
      std::cout << "Money Remaining: $" << money << std::endl;
      std::cout << "Which dairy item would you like to buy? \n\n (1) Cheese "
                   "(-$1.75)(+$2.00), \n (2) Milk "
                   "(-$1.75)(+$2.25)\n (3) Yoghurt (-$1.50)(+$2.50)?"
                << std::endl;
      std::cin >> option;
      if ((option != 1) && (option != 2) && (option != 3)) {
        std::cout << "Money Remaining: $" << money << std::endl;
        std::cout << "Please enter a valid number" << std::endl;
        std::cout << "Which dairy item would you like to buy? \n\n (1) Cheese "
                     "(-$1.75)(+$2.00), \n (2) Milk "
                     "(-$1.75)(+$2.25)\n (3) Yoghurt (-$1.50)(+$2.50)?"
                  << std::endl;
        std::cin >> option;
      }
      if (option >= 1 && option <= 3) {
        Item* newItem = nullptr;
        if (option == 1) {
          newItem = new Cheese;
        } else if (option == 2) {
          newItem = new Milk;
        } else if (option == 3) {
          newItem = new Yoghurt;
        }

        if (money - newItem->getPurchasePrice() < 0) {
          std::cout << "You don't have enough money for this item."
                    << std::endl;
          delete newItem;
        } else {
          std::cout << newItem->getName() << " was added" << std::endl;
          dairyItems.push_back(newItem);
          money -= newItem->getPurchasePrice();
          dairyCounter++;
        }
      }
    }
  }

  std::cout << "Items Bought:" << std::endl;
  for (int i = 0; i < dairyCounter; i++) {
    std::cout << dairyItems[i]->getName() << std::endl;
  }
  std::cout << " " << std::endl;
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

int Inventory::checkProduceExpiry() {
  int counter = 0;
  for (int i = produceCounter - 1; i >= 0; i--) {
    produceItems[i]->determineExpiry();
    if (produceItems[i]->getExpired() == true) {
      delete produceItems[i];
      produceItems[i] = nullptr;
      std::swap(produceItems[i], produceItems[produceCounter - 1]);
      produceItems.pop_back();
      produceCounter--;
      counter = counter + 1;
    }
  };
  return counter;
}

int Inventory::checkDryExpiry() {
  int counter = 0;
  for (int i = dryCounter - 1; i >= 0; i--) {
    dryItems[i]->determineExpiry();
    if (dryItems[i]->getExpired() == true) {
      delete dryItems[i];
      dryItems[i] = nullptr;
      std::swap(dryItems[i], dryItems[dryCounter - 1]);
      dryItems.pop_back();
      dryCounter--;
      counter = counter + 1;
    }
  };
  return counter;
}

int Inventory::checkDairyExpiry() {
  int counter = 0;
  for (int i = dairyCounter - 1; i >= 0; i--) {
    dairyItems[i]->determineExpiry();
    if (dairyItems[i]->getExpired() == true) {
      delete dairyItems[i];
      dairyItems[i] = nullptr;
      std::swap(dairyItems[i], dairyItems[dairyCounter - 1]);
      dairyItems.pop_back();
      dairyCounter--;

      counter = counter + 1;
    }
  };
  return counter;
}

void Inventory::hireEmployee() {
  int choice = 1;
  while (choice == 1) {
    std::cout << "Money Remaining: $" << money << std::endl;
    std::cout << "Do you wish to hire an Employee?" << std::endl;
    std::cout << "(-$20.00 per day) (+$2.00 per customer)" << std::endl;
    std::cout << "Enter 1 for Yes 0 for No" << std::endl;
    std::cin >> choice;
    if ((choice != 1) && (choice != 0)) {
      std::cout << "Money Remaining: $" << money << std::endl;
      std::cout << "Please enter a valid number" << std::endl;
      std::cout << "Do you wish to hire an Employee?" << std::endl;
      std::cout << "(-$20.00 per day) (+$2.00 per customer)" << std::endl;
      std::cout << "Enter 1 for Yes 0 for No" << std::endl;
      std::cin >> choice;
    }
    if (choice == 1) {
      if (money - wage < 0) {
        std::cout << "You do not have enought money to hire an employee"
                  << std::endl;
        break;
      }
      employeeCounter++;
      Employee employee;
      money = money - 20;
      employee.setName();
      std::cout << employee.getName() << " was hired" << std::endl;
    }
  }
}
