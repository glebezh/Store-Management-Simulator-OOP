#include <iostream>
#include <limits>

#include "Inventory.h"
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
#include "Functions.h"

//Functions for inventory class

// Default constructor
Inventory::Inventory() { money = 0; }

// Constructor with money as a parameter.
Inventory::Inventory(double _money) { money = _money; }

// Function to remove an item from the inventory by name. This function searches for an item 
// with the given name in the inventory and removes it if found.
void Inventory::removeItem(string name) {
  for (int i = 0; i < produceCounter; i++) {
    if (produceItems[i]->getName() == name) {

      // Deallocate the memory of the item
      delete produceItems[i];
      produceItems[i] = nullptr;
      
      // Swap the item with the last item in the vector.
      std::swap(produceItems[i], produceItems[produceCounter - 1]);

      // Remove the last item in the vector which is now nullptr.
      produceItems.pop_back();

      // Decrement the produce count
      produceCounter--;
      break;
    }
  }

  for (int i = 0; i < dryCounter; i++) {
    if (dryItems[i]->getName() == name) {

      // Deallocate the memory of the item
      delete dryItems[i];
      dryItems[i] = nullptr;

      // Swap the item with the last item in the vector.
      std::swap(dryItems[i], dryItems[dryCounter - 1]);

      // Remove the last item in the vector which is now nullptr.
      dryItems.pop_back();

      // Decrement the dryCounter by 1.
      dryCounter--;
      break;
    }
  }

  for (int i = 0; i < dairyCounter; i++) {
    if (dairyItems[i]->getName() == name) {

      // Deallocate the memory of the item.
      delete dairyItems[i];
      dairyItems[i] = nullptr;

      // Swap the item with the last item in the vector.
      std::swap(dairyItems[i], dairyItems[dairyCounter - 1]);

      // Remove the last item in the vector which is now nullptr.
      dairyItems.pop_back();

      // Decrement the dairyCounter by 1.
      dairyCounter--;
      break;
    }
  }
}
// Function to let the player buy produce items. The function continously prompts the player to 
// purchase items until the player declines to purchase items.
void Inventory::buyItemProduce() {
  int choice = 1;
  int option = 0;

  // Initialise a while loop to run whilst choice == 1 and the player's money is greater than or equal to 0.
  while (choice == 1 && money >= 0) {
    
    if (produceCounter == 1000) {
      std::cout << "Maximum Capacity for Produce has been reached."
                << std::endl;
      std::cout << "Enter 0 to continue" << std::endl;
      std::cin >> choice;

      // Input validation
      getValidInput(choice, 0,0,0, "Please enter a valid value");
      std::cout << std::endl;
    };
    
    // Ask the user whether they want to buy produce
    std::cout << "Money Remaining: $" << money << std::endl;
    std::cout << "Do you wish to buy Produce (Apples, Bananas or Carrots)?" << std::endl;
    std::cout << "Enter 1 for Yes or 0 for No." << std::endl;

    // Input validation
    getValidInput(choice, 0,0,1, "Please enter a valid number (1 for Yes, 0 for no)");
    std::cout << std::endl;

    // If the user wants to purchase produce, the program asks the user which produce 
    //item they want to purchase.
    if (choice == 1) {
      std::cout << "Which produce item would you like to buy? \n\n (1) Apples "
                   "(-$0.75)(+$1.00) \n (2) Bananas "
                   "(-$0.90)(+$1.25)\n (3) Carrots (-$1.25)(+$1.50)"
                << std::endl;
      std::cout << std::endl;
      std::cout << "Produce Number: ";

      // Input validation
      getValidInput(option, 1,2,3, "Please enter a valid number (1, 2 or 3)");
      std::cout << std::endl;

      // Create a new dynamically allocated item and depending on option chosen by 
      // user make it an apple, banana or carrot.
      Item* newItem = nullptr;
      if (option == 1) {
        newItem = new Apple;
      } else if (option == 2) {
        newItem = new Banana;
      } else if (option == 3) {
        newItem = new Carrot;
      }

      // Check to ensure that the user has enough money to purchase this item.
      if (money - newItem->getPurchasePrice() < 0) {
        std::cout << "You don't have enough money for this item." << std::endl;
        // If not, deallocate the item.
        delete newItem;
      } else {
        // Otherwise let the user the know that the item was added to the inventory.
        std::cout << newItem->getName() << " was added to the inventory." << std::endl;
        std::cout <<  std::endl;

        // Add the item to the end of the produceItems array.
        produceItems.push_back(newItem);

        // Decrement the user's money by the item's purchase price
        money -= newItem->getPurchasePrice();

        // Increment produce counter by 1
        produceCounter++;
      }
    }
  }
  // Initialise a for loop to print the items purchased. 
  std::cout << "Items Bought:" << std::endl;
  for (int i = 0; i < produceCounter; i++) {
    std::cout << produceItems[i]->getName() << std::endl;
  }
  std::cout << " " << std::endl;
}

// Function to let the player buy Dry items. The function continously prompts the player to 
// purchase items until the player declines to purchase items.
void Inventory::buyItemDry() {
  int choice = 1;
  int option = 0;
  while (choice == 1 && money >= 0) {
    if (dryCounter == 1000) {
      std::cout << "Maximum Capacity for Dry has been reached." << std::endl;
      std::cout << "Enter 0 to continue" << std::endl;

      // Input validation
      getValidInput(choice, 0,0,0, "Please enter a valid value");
      std::cout << std::endl;
    }
    // Ask the user whether they want to buy dry items.
    std::cout << "Money Remaining: $" << money << std::endl;
    std::cout << "Do you wish to buy Dry (Biscuit, Bread or Chocolate)?" << std::endl;
    std::cout << "Enter 1 for Yes or 0 for No" << std::endl;

    //Input Validation
    getValidInput(choice, 0,1,1, "Please enter a valid number (1 for Yes, 0 for No)");
    std::cout << std::endl;
  

    // If the user wants to purchase dry items, the program asks the user which items 
    // item they want to purchase.
    if (choice == 1) {
      std::cout << "Which dry item would you like to buy? \n\n (1) Biscuit "
                   "(-$0.90)(+$1.25) \n (2) Bread "
                   "(-$0.90)(+$1.25)\n (3) Chocolate (-$1.50)(+$2.25)"
                << std::endl;
      std::cout << std::endl;
      std::cout << "Dry Number: ";

      getValidInput(option, 1,2,3, "Please enter a valid number (1, 2 or 3)");
      std::cout << std::endl;

      // Create a new dynamically allocated item and depending on option chosen by 
      // user make it a biscuit, bread or chocolate item.
      Item* newItem = nullptr;
      if (option == 1) {
        newItem = new Biscuit;
      } else if (option == 2) {
        newItem = new Bread;
      } else if (option == 3) {
        newItem = new Chocolate;
      }

      // Check to ensure that the user has enough money to purchase this item.
      if (money - newItem->getPurchasePrice() < 0) {
        std::cout << "You don't have enough money for this item." << std::endl;
        //if not, deallocate the item.
        delete newItem;
        // Otherwise, let the user know that the item was added.
      } else {
        std::cout << newItem->getName() << " was added" << std::endl;

        // Add the item to the end of the dryItems array.
        dryItems.push_back(newItem);

        // Adjust the player's money based on the cost of the item they purchased.
        money -= newItem->getPurchasePrice();

        // Increment dryCounter by 1.
        dryCounter++;
      }
    }
  }

  // Initialise a for loop to print the items purchased. 
  std::cout << "Items Bought:" << std::endl;
  for (int i = 0; i < dryCounter; i++) {
    std::cout << dryItems[i]->getName() << std::endl;
  }
  std::cout << " " << std::endl;
}

// Function to let the player buy Dairy items. The function continously prompts the player to 
// purchase items until the player declines to purchase items.
void Inventory::buyItemDairy() {
  int choice = 1;
  int option = 0;
  while (choice == 1 && money >= 0) {
    if (dairyCounter == 1000) {
      std::cout << "Maximum Capacity for Dairy has been reached." << std::endl;
      std::cout << "Enter 0 to continue" << std::endl;
      
      // Input validation
      getValidInput(choice, 0,0,0, "EPlease enter a valid value");
      std::cout << std::endl;
    }

    // Ask the user whether they want to but Dairy items.
    std::cout << "Money Remaining: $" << money << std::endl;
    std::cout << "Do you wish to buy Dairy (Cheese, Milk or Yoghurt)?"<< std::endl;
    std::cout << "Enter 1 for Yes or 0 for No" << std::endl;

    // Input Validation
    getValidInput(choice, 0,1,1, "Please enter a valid number (1 for Yes, 0 for No)");
    std::cout << std::endl;

  
    // If the user wants to purchase dairy items, the program asks the user which items 
    // they want to purchase.
    if (choice == 1) {
      std::cout << "Which dairy item would you like to buy? \n\n (1) Cheese "
                   "(-$1.75)(+$2.00) \n (2) Milk "
                   "(-$1.75)(+$2.25)\n (3) Yoghurt (-$1.50)(+$2.50)"
                << std::endl;
      std::cout << std::endl;
      std::cout << "Dairy Number: ";

      // Input Validation
      getValidInput(option, 1,2,3, "Please enter a valid number (1, 2 or 3)");
      std::cout << std::endl;

      // Create a new dynamically allocated item and depending on option chosen by 
      // user make it a cheese, milk or yoghurt item.
      Item* newItem = nullptr;
      if (option == 1) {
        newItem = new Cheese;
      } else if (option == 2) {
        newItem = new Milk;
      } else if (option == 3) {
        newItem = new Yoghurt;
      }

      // Check to ensure that the user has enough money to purchase this item.
      if (money - newItem->getPurchasePrice() < 0) {
        std::cout << "You don't have enough money for this item." << std::endl;
        //if not, deallocate the item.
        delete newItem;
      } else {
        // Otherwise, let the user know that the item was added to the inventory.
        std::cout << newItem->getName() << " was added" << std::endl;

        // Added the new item to end of the inventory.
        dairyItems.push_back(newItem);

        // Deduct the amount of money corresponding to the item purchase price from the player's money.
        money -= newItem->getPurchasePrice();

        // Incremenet dairy counter by 1.
        dairyCounter++;
      }
    }
  }
  // Print the items purchased by the player, using a for loop.
  std::cout << "Items Bought:" << std::endl;
  for (int i = 0; i < dairyCounter; i++) {
    std::cout << dairyItems[i]->getName() << std::endl;
  }
  std::cout << " " << std::endl;
}

// Void function which prints all of the produce items in the user's inventory.
void Inventory::showproduceItems() {
  std::cout << "Produce Items:" << std::endl;
  for (int i = 0; i < produceCounter; i++) {
    std::cout << produceItems[i]->getName() << std::endl;
  }
}

// Void function which prints all of the dry items in the user's inventory.
void Inventory::showdryItems() {
  std::cout << "Dry Items:" << std::endl;
  for (int i = 0; i < dryCounter; i++) {
    std::cout << dryItems[i]->getName() << std::endl;
  }
}

// Void function which prints all of the dairy items in the user's inventory.
void Inventory::showdairyItems() {
  std::cout << "Dairy Items:" << std::endl;
  for (int i = 0; i < dairyCounter; i++) {
    std::cout << dairyItems[i]->getName() << std::endl;
  }
}

// Expiry checker function to delete expired produce items from the inventory.
int Inventory::checkProduceExpiry() {
  int expired_items = 0;
  for (int i = produceCounter - 1; i >= 0; i--) {
    // Increase the counter of each inventory item by 1.
    produceItems[i]->setCounter(produceItems[i]->getCounter()+1);

    // Use the determine expiry function to set the value of the expired variable.
    produceItems[i]->determineExpiry();

    // Use an if statement to check if the item is expired.
    if (produceItems[i]->getExpired() == true) {

      // Deallocate the memory of the item
      delete produceItems[i];
      produceItems[i] = nullptr;

      // Swap the item with the last item in the vector.
      std::swap(produceItems[i], produceItems[produceCounter - 1]);

      // Remove the last element in the vector.
      produceItems.pop_back();

      // Decrement the producecounter variable by 1 and increment the expired_items variable by 1.
      produceCounter--;
      expired_items++;
    }
  };
  return expired_items;
}

//Expiry checker function to deleted expired dry items from the inventory.
int Inventory::checkDryExpiry() {
  int expired_items = 0;
  for (int i = dryCounter - 1; i >= 0; i--) {
    // Increase the counter of each inventory item by 1.
    dryItems[i]->setCounter(dryItems[i]->getCounter()+1);
    
    // Use the determine expiry function to set the value of the expired variable.
    dryItems[i]->determineExpiry();

    // Use an if statement to check if the item is expired.
    if (dryItems[i]->getExpired() == true) {

      // Deallocate the memory of the item
      delete dryItems[i];
      dryItems[i] = nullptr;

      // Swap the item with the last item in the vector.
      std::swap(dryItems[i], dryItems[dryCounter - 1]);

      // Remove the last element in the vector.
      dryItems.pop_back();

      // Decrement the drycounter variable by 1 and increment the expired_items variable by 1.
      dryCounter--;
      expired_items++; 
    }
  };
  return expired_items;
}

//Expiry checker function to deleted expired dairy items from the inventory.
int Inventory::checkDairyExpiry() {
  int expired_items = 0;
  for (int i = dairyCounter - 1; i >= 0; i--) {
    // Increase the counter of each inventory item by 1.
    dairyItems[i]->setCounter(dairyItems[i]->getCounter()+1);

    // Use the determine expiry function to set the value of the expired variable
    dairyItems[i]->determineExpiry();

    // Use an if statement to check if the item is expired.
    if (dairyItems[i]->getExpired() == true) {

      // Deallocate the memory of the item
      delete dairyItems[i];
      dairyItems[i] = nullptr;

      // Swap the item with the last item in the vector.
      std::swap(dairyItems[i], dairyItems[dairyCounter - 1]);

      // Remove the last element in the vector.
      dairyItems.pop_back();

      // Decrement the dairycounter variable by 1 and increment the expired_items variable by 1.
      dairyCounter--;
      expired_items = expired_items + 1;
    }
  };
  return expired_items;
}

// Function to hire employees for the store. The function will continously prompt the user to hire an employee
// until the player declines.
void Inventory::hireEmployee() {
  int choice = 1;

  // Initialise a while loop which continues running whilst choice == 1
  while (choice == 1) {

    // Ask the user whether they want to hire an employee.
    std::cout << "Money Remaining: $" << money << std::endl;
    std::cout << "Do you wish to hire an Employee?" << std::endl;
    std::cout << "(-$10.00 per day) (+$2.00 per customer)" << std::endl;
    std::cout << "Enter 1 for Yes 0 for No" << std::endl;
    
    // Input Validation
    getValidInput(choice, 0,0,1, "Please enter a valid number (1 for Yes, 0 for No)");
    std::cout << std::endl;

    // If the user does, perform some preliminary checks to ensure the user has enough money.
    if (choice == 1) {
      if (money - wage < 0) {
        std::cout << "You do not have enough money to hire an employee"
                  << std::endl;
        break;
      }
      // Create an employee and set the name.
      Employee employee;
      employee.setName();

      // Increment employeeCounter by 1.
      employeeCounter++;
  
      // Adjust the player's money.
      money = money - wage;

      // Let the user know that an employee was hired.
      std::cout << employee.getName() << " was hired" << std::endl;
    }
  }
}
// Void function to create different item type vectors based on save file. 
void Inventory::initializeProduceItems(const std::vector<std::string>& items) {
  for (const std::string& itemName : items) {
    if (itemName == "Apple") {
      produceItems.push_back(new Apple);
    }
    if (itemName == "Banana") {
      produceItems.push_back(new Banana);
    }
    if (itemName == "Carrot") {
      produceItems.push_back(new Carrot);
    }
  }
}

// Void function to create different item type vectors based on save file.
void Inventory::initializeDryItems(const std::vector<std::string>& items) {
  for (const std::string& itemName : items) {
    if (itemName == "Biscuit") {
      dryItems.push_back(new Biscuit);
    }
    if (itemName == "Bread") {
      dryItems.push_back(new Bread);
    }
    if (itemName == "Chocolate") {
      dryItems.push_back(new Chocolate);
    }
  }
}

// Void function to create different item types vectors based on save file.
void Inventory::initializeDairyItems(const std::vector<std::string>& items) {
  for (const std::string& itemName : items) {
    if (itemName == "Cheese") {
      dairyItems.push_back(new Cheese);
    }
    if (itemName == "Milk") {
      dairyItems.push_back(new Milk);
    }
    if (itemName == "Yoghurt") {
      dairyItems.push_back(new Yoghurt);
    }
  }
}
