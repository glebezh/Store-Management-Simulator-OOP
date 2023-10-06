#include <iostream>

#include "Apple.h"
#include "Banana.h"
#include "Carrot.h"
#include "Item.h"

int main() {
  int counter = 0;
  int choice = 1;
  int option = 0;

  int** array[10];

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
      counter = counter + 1;
      std::cout << "Do you wish to buy Apples (1), Bananas (2) or Carrots (3)?"
                << std::endl;
      cin >> option;
      if ((option != 1) || (option != 2) || option != 3) {
        std::cout << "Please enter a valid number" << std::endl;
        std::cout
            << "Do you wish to buy Apples (1), Bananas (2) or Carrots (3)?"
            << std::endl;
        cin >> option;
      }
      if (option == 1) {
        new Apple;
        std::cout << "Apple was added" << std::endl;
      };
      if (option == 2) {
        new Banana;
        std::cout << "Banana was added" << std::endl;
      };
      if (option == 3) {
        new Carrot;
        std::cout << "Carrot was added" << std::endl;
      }
    }
  };

  return 0;
}