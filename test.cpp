#include <iostream>

#include "Apple.h"
#include "Banana.h"
#include "Carrot.h"
#include "Item.h"

int main() {
  double money = 11;
  int counter = 0;
  int choice = 1;
  int option = 0;

  Item* inventory[10];

  while (choice == 1) {
    std::cout << "Do you wish to buy Produce (Apples, Bananas or Carrots)?"
              << std::endl;
    std::cout << "Enter 1 for Yes or 0 for No" << std::endl;
    cin >> choice;
    while ((choice != 1) && (choice != 0)) {
      std::cout << "Please enter a valid number" << std::endl;
      std::cout << "Do you wish to buy Produce (Apples, Bananas or Carrots)?"
                << std::endl;
      std::cout << "Enter 1 for Yes or 0 for No" << std::endl;
      cin >> choice;
    }
    if (choice == 1) {
      if (counter == 10) {
        std::cout << "Inventory Full" << std::endl;
        break;
      };
      std::cout << "Do you wish to buy Apples (1), Bananas (2) or Carrots (3)?"
                << std::endl;
      cin >> option;
      if ((option != 1) && (option != 2) && (option != 3)) {
        std::cout << "Please enter a valid number" << std::endl;
        std::cout << "Do you wish to buy Apples (1) Bananas (2) or Carrots (3)?"
                  << std::endl;
        cin >> option;
      }
      if (option == 1) {
        std::cout << "Apple was added" << std::endl;
        inventory[counter] = new Apple;
        money = money - inventory[counter]->getsellPrice();
      };
      if (option == 2) {
        std::cout << "Banana was added" << std::endl;
        inventory[counter] = new Banana;
        money = money - inventory[counter]->getsellPrice();
      };
      if (option == 3) {
        std::cout << "Carrot was added" << std::endl;
        inventory[counter] = new Carrot;
        money = money - inventory[counter]->getsellPrice();
      }
      counter = counter + 1;
    }
    if (money < 0) {
      std::cout << "You have run out of Money" << std::endl;
      break;
    }
  };

  std::cout << "Produce Bought:" << std::endl;
  for (int i = 0; i < counter; i++) {
    std::cout << inventory[i]->getName() << std::endl;
  };

  std::cout << "Money Remaining: $" << money << std::endl;

  return 0;
}