#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Inventory.h"
#include "Item.h"
#include "Person.h"
#include "Functions.h"

using namespace std;

// Class containing information for Customer object
class Customer : public Person {
 private:
 //variables for customer
  double moneySpent;
  int itemCounter;
  string wantedItem1;
  string wantedItem2;
  string wantedItem3;
  double rating;

 public:
 //constructors
  Customer() {
    name = "";
    wantedItem1 = "";
    wantedItem2 = "";
    wantedItem3 = "";
    moneySpent = 0;
    itemCounter = 0;
    rating = 0; 
  }
  Customer(string _name) : Person(_name) {
    wantedItem1 = "";
    wantedItem2 = ""; 
    wantedItem3 = "";
    moneySpent = 0;
    itemCounter = 0;
    rating = 0;
  }
  //Get and Set functions
  string getName() { return name; }
  double getMoneySpent() { return moneySpent; };
  void setName(std::string setName) { name = setName; };

  string getDesiredItem1() { return wantedItem1; };
  string getDesiredItem2() { return wantedItem2; };
  string getDesiredItem3() { return wantedItem3; };

  void setDesiredItem1(std::string itemName) { wantedItem1 = itemName; };
  void setDesiredItem2(std::string itemName) { wantedItem2 = itemName; };
  void setDesiredItem3(std::string itemName) { wantedItem3 = itemName; };

  // Void function which allows customers to purchase items from the inventory.
  // Accepts an inventory as the argument.
  void buyFromInventory1(Inventory& inventory) {
    Item* item = nullptr;

    for (int i = 0; i < inventory.getProduceCounter(); i++) {
      // Use an if statement to check whether the item desired by the customer is 
      // located in the inventory.
      if (inventory.getProduceItems()[i]->getName() == wantedItem1) {

        // Set the item variable to the chosen item.
        item = inventory.getProduceItems()[i];

        // Increment the number of items by 1. 
        itemCounter++;

        // Set the moneyspent by the customer. 
        moneySpent = moneySpent + item->getSellPrice();

        //Remove the item from the inventory using inventory.removeItem() function.
        inventory.removeItem(item->getName());
        break;
      }
    }

    for (int i = 0; i < inventory.getDryCounter(); i++) {
      // Use an if statement to check whether the item desired by the customer is 
      // located in the inventory.
      if (inventory.getDryItems()[i]->getName() == wantedItem1) {

        // Set the item variable to the chosen item.
        item = inventory.getDryItems()[i];

        // Increment the number of items by 1. 
        itemCounter++;

        // Set the moneyspent by the customer. 
        moneySpent = moneySpent + item->getSellPrice();

        //Remove the item from the inventory using inventory.removeItem() function.
        inventory.removeItem(item->getName());
        break;
      }
    }
    for (int i = 0; i < inventory.getDairyCounter(); i++) {
      // Use an if statement to check whether the item desired by the customer is 
      // located in the inventory.
      if (inventory.getDairyItems()[i]->getName() == wantedItem1) {

        // Set the item variable to the chosen item.
        item = inventory.getDairyItems()[i];

        // Increment the number of items by 1.
        itemCounter++;

        // Set the moneyspent by the customer.
        moneySpent = moneySpent + item->getSellPrice();

        //Remove the item from the inventory using inventory.removeItem() function.
        inventory.removeItem(item->getName());
        break;
      }
    }
  }
  
  // Void function which allows customers to purchase items from the inventory.
  // Accepts an inventory as the argument.
  void buyFromInventory2(Inventory& inventory) {
    Item* item = nullptr;

    for (int i = 0; i < inventory.getProduceCounter(); i++) {
      // Use an if statement to check whether the item desired by the customer is 
      // located in the inventory.
      if (inventory.getProduceItems()[i]->getName() == wantedItem2) {
        
        // Set the item variable to the chosen item.
        item = inventory.getProduceItems()[i];

        // Increment the number of items by 1.
        itemCounter++;

        // Set the moneyspent by the customer.
        moneySpent = moneySpent + item->getSellPrice();

        //Remove the item from the inventory using inventory.removeItem() function.
        inventory.removeItem(item->getName());
        break;
      }
    }
    for (int i = 0; i < inventory.getDryCounter(); i++) {
      // Use an if statement to check whether the item desired by the customer is 
      // located in the inventory.
      if (inventory.getDryItems()[i]->getName() == wantedItem2) {

        // Set the item variable to the chosen item.
        item = inventory.getDryItems()[i];

        // Increment the number of items by 1.
        itemCounter++;

        // Set the moneyspent by the customer.
        moneySpent = moneySpent + item->getSellPrice();

        //Remove the item from the inventory using inventory.removeItem() function.
        inventory.removeItem(item->getName());
        break;
      }
    }

    for (int i = 0; i < inventory.getDairyCounter(); i++) {
      // Use an if statement to check whether the item desired by the customer is 
      // located in the inventory.
      if (inventory.getDairyItems()[i]->getName() == wantedItem2) {

        // Set the item variable to the chosen item.
        item = inventory.getDairyItems()[i];

        // Increment the number of items by 1.
        itemCounter++;

        // Set the moneyspent by the customer.
        moneySpent = moneySpent + item->getSellPrice();

        //Remove the item from the inventory using inventory.removeItem() function.
        inventory.removeItem(item->getName());
        break;
      }
    }
  };

  // Void function which allows customers to purchase items from the inventory.
  // Accepts an inventory as the argument.
  void buyFromInventory3(Inventory& inventory) {
    Item* item = nullptr;

    for (int i = 0; i < inventory.getProduceCounter(); i++) {
      // Use an if statement to check whether the item desired by the customer is 
      // located in the inventory.
      if (inventory.getProduceItems()[i]->getName() == wantedItem3) {

        // Set the item variable to the chosen item.
        item = inventory.getProduceItems()[i];
        
        // Increment the number of items by 1.
        itemCounter++;

        // Set the moneyspent by the customer.
        moneySpent = moneySpent + item->getSellPrice();

        //Remove the item from the inventory using inventory.removeItem() function.
        inventory.removeItem(item->getName());
        break;
      }
    }
    for (int i = 0; i < inventory.getDryCounter(); i++) {
      // Use an if statement to check whether the item desired by the customer is 
      // located in the inventory.
      if (inventory.getDryItems()[i]->getName() == wantedItem3) {

        // Set the item variable to the chosen item.
        item = inventory.getDryItems()[i];
        
        // Increment the number of items by 1.
        itemCounter++;

        // Set the moneyspent by the customer.
        moneySpent = moneySpent + item->getSellPrice();

        //Remove the item from the inventory using inventory.removeItem() function.
        inventory.removeItem(item->getName());
        break;
      }
    }
    for (int i = 0; i < inventory.getDairyCounter(); i++) {
      // Use an if statement to check whether the item desired by the customer is 
      // located in the inventory.
      if (inventory.getDairyItems()[i]->getName() == wantedItem3) {

        // Set the item variable to the chosen item.
        item = inventory.getDairyItems()[i];

        // Increment the number of items by 1.
        itemCounter++;

        // Set the moneyspent by the customer.
        moneySpent = moneySpent + item->getSellPrice();

        //Remove the item from the inventory using inventory.removeItem() function.
        inventory.removeItem(item->getName());
        break;
      }
    }
  }
  
  // Simple function to determine the store rating based on the number of items 
  // the customer was able to purchase.
  int itemsBought() {
    if (itemCounter == 3) {
      rating = 3;
    };
    if (itemCounter == 2) {
      rating = 2;
    };
    if (itemCounter == 1) {
      rating = 1;
    };

    if (itemCounter == 0) {
      rating = 0;
    };
    return itemCounter;
  };

  // Simple function to adjust the store rating based on the 
  // number of items the next customer was able to purchase
  double setRating(double currentRating) {
    double newRating = 0;
    newRating = (currentRating + rating) / 2;
    return newRating;
  }

};

#endif