#include <fstream>
#include <iostream>
#include <limits>

#include "Customer.h"
#include "Employee.h"
#include "Inventory.h"
#include "Load.h"
#include "Random.h"

// These functions are in a different file
extern void saveGame1(Inventory inven, int days, double rating, string name);
extern void saveGame2(Inventory inven, int days, double rating, string name);

int main() {
  // initiallizing vars
  initRandom();
  srand(time(0));
  int dayCounter = 1;
  double totalMoney = 100;
  double rating = 3;
  int choice = 0;
  int random = 0;
  int save = 2;
  int saveNow = 0;

  std::string storeName = "";
  // save check
  std::cout << "Do you want to load a save?" << std::endl;
  std::cout << "Yes (1) or No (0)" << std::endl;

  while (true) {
    std::cin >> save;
    if (std::cin.good() && (save == 1 || save == 0)) {
      break;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<int>::max(), '\n');
      std::cout << "Please enter a valid value." << std::endl;
    }
  }

  if (save == 1) {
    Load loadSave(1);
    std::cout << "Save File Loaded" << std::endl;
    std::cout << loadSave.getName() << std::endl;
    storeName = loadSave.getName();
    rating = loadSave.getRating();
    totalMoney = loadSave.getMoney();
    dayCounter = loadSave.getDays();
  };

  // Allows the user to enter a desire name for the store
  if (save == 0) {
    std::cout << "Please enter your store name:" << std::endl;
    std::cin >> storeName;
  };

  // inventory creation
  Inventory hold(totalMoney);

  // will add items to the inventory from the save file if selected to do so
  if (save == 1) {
    Load loadSave2(2);
    std::vector<std::string> loadedProduce = loadSave2.getLoadedProduce();
    std::vector<std::string> loadedDry = loadSave2.getLoadedDry();
    std::vector<std::string> loadedDairy = loadSave2.getLoadedDairy();

    hold.initializeProduceItems(loadedProduce);
    hold.initializeDryItems(loadedDry);
    hold.initializeDairyItems(loadedDairy);
    hold.updateInventory(loadSave2.getProduceItems(), loadSave2.getDryItems(),
                         loadSave2.getDairyItems());
  }

  // loop decides if game ends
  while ((rating >= 0.5) && (hold.getMoney() > 0)) {
    // tells player info about games state and asks if any stock needs to be
    // purchased
    std::cout << storeName << " is now on Day " << dayCounter << std::endl;
    std::cout << "Your Current Money: $" << hold.getMoney() << std::endl;
    std::cout << "Your Current Rating: " << rating << std::endl;
    int numCustomers = generateRandom(1, 2 * dayCounter + 1);
    std::cout << "" << std::endl;

    std::cout << "Current Inventory:" << std::endl;
    hold.showproduceItems();
    hold.showdryItems();
    hold.showdairyItems();
    std::cout << "" << std::endl;

    hold.buyItemProduce();
    hold.buyItemDry();
    hold.buyItemDairy();

    std::cout << "New Inventory:" << std::endl;
    hold.showproduceItems();
    hold.showdryItems();
    hold.showdairyItems();
    std::cout << "" << std::endl;

    hold.hireEmployee();
    std::cout << "" << std::endl;
    std::cout << "Enter 0 to start the day" << std::endl;
    std::cin >> random;
    if (random != 0) {
      std::cout << "Please enter a valid number" << std::endl;
      std::cout << "Enter 0 to start the day" << std::endl;
      std::cin >> random;
    }

    for (int i = 0; i < numCustomers; i++) {
      Customer customer;

      std::vector<std::string> names = {
          "Ila",       "Gunner", "Stevie",    "Kevin",   "Cali",     "Drew",
          "Paris",     "Roman",  "Giselle",   "Uriel",   "Magnolia", "Orion",
          "Elena",     "Kairo",  "Aubriella", "Cash",    "Grace",    "Keegan",
          "Mary",      "Elliot", "Denver",    "Alex",    "Saige",    "Kamryn",
          "Rayne",     "Harlem", "Mya",       "Isaiah",  "Sophia",   "Cyrus",
          "Katherine", "Finn",   "Leila",     "John",    "Mina",     "Joel",
          "Anahi",     "Corey",  "Amayah",    "Archie",  "Cadence",  "Rex",
          "Ainhoa",    "Kylan",  "Melina",    "Jacoby",  "Ruby",     "Robert",
          "Kai",       "Roy",    "Sevyn",     "Madden",  "Dalayza",  "Felipe",
          "Madeline",  "Collin", "Lennox",    "Braylen", "Winnie",   "Connor"};

      customer.setName(names[generateRandom(0, names.size() - 1)]);

      std::vector<std::string> items = {"Apple",   "Banana", "Carrot",
                                        "Biscuit", "Bread",  "Chocolate",
                                        "Cheese",  "Milk",   "Yoghurt"};
      // Selects 3 random items for the cusomer to buy
      customer.setDesiredItem1(items[generateRandom(0, items.size() - 1)]);
      customer.setDesiredItem2(items[generateRandom(0, items.size() - 1)]);
      customer.setDesiredItem3(items[generateRandom(0, items.size() - 1)]);

      // Buys the 3 random items
      customer.buyFromInventory1(hold);
      customer.buyFromInventory2(hold);
      customer.buyFromInventory3(hold);

      hold.setMoney(hold.getMoney() + customer.getMoneySpent());
      hold.setMoney(hold.getMoney() +
                    (hold.getEmployeeCount() * numCustomers * 2));

      std::cout << customer.getName() << " "
                << " bought " << customer.itemsBought() << " items"
                << std::endl;

      // updates the store rating dependent on items bought
      rating = customer.setRating(rating);
    };
    std::cout << hold.checkProduceExpiry() << " Produce Items have Expired"
              << std::endl;
    std::cout << hold.checkDryExpiry() << " Dry Items have Expired"
              << std::endl;
    std::cout << hold.checkDairyExpiry() << " Dairy Items have Expired"
              << std::endl;

    std::cout << "" << std::endl;
    std::cout << "Current Money:" << hold.getMoney() << std::endl;

    rating = rating + (hold.getEmployeeCount() * 0.2);

    std::cout << "Current Rating:" << rating << std::endl;
    std::cout << "" << std::endl;

    std::cout << "You have Finished Day " << dayCounter << std::endl;
    std::cout << "Enter 0 to Continue" << std::endl;
    std::cin >> choice;

    if (choice != 0) {
      std::cout << "Please enter a valid number" << std::endl;
      std::cout << "Enter 0 to Continue" << std::endl;
      std::cin >> choice;
    }

    dayCounter = dayCounter + 1;
    hold.resetEmployee();

    std::cout << "Do you want to save now?" << std::endl;
    std::cout << "Yes (1) or No (0)" << std::endl;
    // std::cin >> saveNow;

    while (true) {
      std::cin >> saveNow;
      if (std::cin.good() && (saveNow == 0 || saveNow == 1)) {
        break;
      } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        std::cout << "Please enter a valid number (1 for Yes, 0 for No)"
                  << std::endl;
      }
    }

    if (saveNow == 1) {
      saveGame1(hold, dayCounter, rating, storeName);
      saveGame2(hold, dayCounter, rating, storeName);
      std::cout << "Game Saved" << std::endl;
      break;
    }
  };
  // rating check, if lower than 0.5 game ends
  if (rating < 0.5) {
    system("clear");
    std::cout << "Game Over" << std::endl;
    std::cout << "Your store had an abysmal rating and had to close!"
              << std::endl;
    std::cout << "Better Luck Next Time" << std::endl;
  }

  if (hold.getMoney() < 0) {
    system("clear");
    std::cout << "Game Over" << std::endl;
    std::cout << "Your store when bankrupt and had to close!" << std::endl;
    std::cout << "Better Luck Next Time" << std::endl;
  }
  return 0;
}