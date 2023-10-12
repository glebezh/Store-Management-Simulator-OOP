#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

#include "Inventory.h"
#include "Item.h"
#include "Person.h"
#include "Random.h"
using namespace std;

std::vector<std::string> products = {"Apple", "Banana", "Biscuit", "Bread", "Carrot", "Cheese", "Chocolate", "Milk", "Yoghurt"};

class Customer : public Person {
 private:
  double moneySpent;
  int itemCounter;
  string wantedItem1;
  string wantedItem2;
  string wantedItem3;
  double rating = 0;

 public:
  Customer() {
    name = "";
    wantedItem1 = "";
    wantedItem2 = "";
    wantedItem3 = "";        //file:////usr/share/doc/HTML/en-US/index.html
  }
  Customer(string _name):Person(_name){
    wantedItem1 = generateRandomItem(products);//Randomly generate here
    wantedItem2 = generateRandomItem(products);  // and here
    wantedItem3 = generateRandomItem(products);  // and here
    moneySpent = 0;
    itemCounter = 0;
  }
  string getName(){return name;}

  double getMoneySpent() { return moneySpent; };

  void buyFromInventory1(Inventory& inventory) {
    Item* item = nullptr;

    for (int i = 0; i < inventory.getProduceCounter(); i++) {
      if (inventory.getProduceItems()[i]->getName() == wantedItem1) {
        item = inventory.getProduceItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        inventory.removeItem(item->getName());
        break;
      }
    }
    for (int i = 0; i < inventory.getDryCounter(); i++) {
      if (inventory.getDryItems()[i]->getName() == wantedItem1) {
        item = inventory.getDryItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        inventory.removeItem(item->getName());
        break;
      }
    }
    for (int i = 0; i < inventory.getDairyCounter(); i++) {
      if (inventory.getDairyItems()[i]->getName() == wantedItem1) {
        item = inventory.getDairyItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        inventory.removeItem(item->getName());
        break;
      }
    }
  }

  void buyFromInventory2(Inventory& inventory) {
    Item* item = nullptr;

    for (int i = 0; i < inventory.getProduceCounter(); i++) {
      if (inventory.getProduceItems()[i]->getName() == wantedItem2) {
        item = inventory.getProduceItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        inventory.removeItem(item->getName());
        break;
      }
    }
    for (int i = 0; i < inventory.getDryCounter(); i++) {
      if (inventory.getDryItems()[i]->getName() == wantedItem2) {
        item = inventory.getDryItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        inventory.removeItem(item->getName());
        break;
      }
    }
    for (int i = 0; i < inventory.getDairyCounter(); i++) {
      if (inventory.getDairyItems()[i]->getName() == wantedItem2) {
        item = inventory.getDairyItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        inventory.removeItem(item->getName());
        break;
      }
    }
  };

  void buyFromInventory3(Inventory& inventory) {
    Item* item = nullptr;

    for (int i = 0; i < inventory.getProduceCounter(); i++) {
      if (inventory.getProduceItems()[i]->getName() == wantedItem3) {
        item = inventory.getProduceItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        inventory.removeItem(item->getName());
        break;
      }
    }
    for (int i = 0; i < inventory.getDryCounter(); i++) {
      if (inventory.getDryItems()[i]->getName() == wantedItem3) {
        item = inventory.getDryItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        inventory.removeItem(item->getName());
        break;
      }
    }
    for (int i = 0; i < inventory.getDairyCounter(); i++) {
      if (inventory.getDairyItems()[i]->getName() == wantedItem3) {
        item = inventory.getDairyItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        inventory.removeItem(item->getName());
        break;
      }
    }
  }

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

  double setRating(double currentRating) {
    double newRating = 0;

    newRating = (currentRating + rating) / 2;

    return newRating;
  }

  void setName(std::string setName) { name = setName; };
  
  string getDesiredItem1() { return wantedItem1;};
  string getDesiredItem2(){ return wantedItem2;};
  string getDesiredItem3() { return wantedItem3;};
};
#endif