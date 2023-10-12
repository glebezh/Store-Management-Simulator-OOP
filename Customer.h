#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

#include "Inventory.h"
#include "Item.h"
#include "People.h"
#include "Store.h"


class Customer : public People {
 private:
  double moneySpent = 0;
  int itemCounter = 0;
  std::string wantedItem1;
  std::string wantedItem2;
  std::string wantedItem3;

 public:
  Customer() {}

  double getMoneySpent() { return moneySpent; };

  void buyFromInventory1(Inventory& inventory) {
    Item* item = nullptr;

    for (int i = 0; i < inventory.getProduceCounter(); i++) {
      if (inventory.getProduceItems()[i]->getName() == wantedItem1) {
        item = inventory.getProduceItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        break;
      }
    }
    for (int i = 0; i < inventory.getDryCounter(); i++) {
      if (inventory.getDryItems()[i]->getName() == wantedItem1) {
        item = inventory.getDryItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        break;
      }
    }
    for (int i = 0; i < inventory.getDairyCounter(); i++) {
      if (inventory.getDairyItems()[i]->getName() == wantedItem1) {
        item = inventory.getDairyItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
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
        break;
      }
    }
    for (int i = 0; i < inventory.getDryCounter(); i++) {
      if (inventory.getDryItems()[i]->getName() == wantedItem2) {
        item = inventory.getDryItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        break;
      }
    }
    for (int i = 0; i < inventory.getDairyCounter(); i++) {
      if (inventory.getDairyItems()[i]->getName() == wantedItem2) {
        item = inventory.getDairyItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
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
        break;
      }
    }
    for (int i = 0; i < inventory.getDryCounter(); i++) {
      if (inventory.getDryItems()[i]->getName() == wantedItem3) {
        item = inventory.getDryItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        break;
      }
    }
    for (int i = 0; i < inventory.getDairyCounter(); i++) {
      if (inventory.getDairyItems()[i]->getName() == wantedItem3) {
        item = inventory.getDairyItems()[i];
        itemCounter++;
        moneySpent = moneySpent + item->getSellPrice();
        break;
      }
    }
  }
  int itemsBought() { return itemCounter; };

  void setDesiredItem1(std::string itemName) { wantedItem1 = itemName; };
  void setDesiredItem2(std::string itemName) { wantedItem2 = itemName; };
  void setDesiredItem3(std::string itemName) { wantedItem3 = itemName; };
};

#endif