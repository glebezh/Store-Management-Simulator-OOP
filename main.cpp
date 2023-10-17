#include <fstream>
#include <iostream>
#include <limits>
#include <string>

#include "Customer.h"
#include "Employee.h"
#include "Inventory.h"
#include "Load.h"
#include "Functions.h"


// These functions are in a different file
extern void saveGame1(Inventory inven, int days, double rating, string name);
extern void saveGame2(Inventory inven, int days, double rating, string name);

int main() {
  // Initialising Variables
  initRandom();
  srand(time(0));
  int dayCounter = 1;
  double totalMoney = 100;
  double rating = 3;
  int choice = 0;
  int random = 0;
  int save = 2;
  int saveNow = 0;
  int main_menu = 0;

  std::cout << "Welcome to the Store Management Simulator!" << std::endl;

  std::string storeName = "";

  // Prompt the user to load in a save if they want.
  std::cout << "Would you like to load a save?" << std::endl;
  std::cout << "Yes (1) or No (0)" << std::endl;

  // Run the getValidInput function to validate user input.
  getValidInput(save, 0,0,1, "Please enter a valid number value (0 or 1)");
  std::cout << std::endl;

  // If the user wants to load in a save, create a load object and set variables to values from the object.
  if (save == 1) {
    Load loadSave(1);
    std::cout << "Save File Loaded" << std::endl;
    std::cout << loadSave.getName() << std::endl;
    storeName = loadSave.getName();
    rating = loadSave.getRating();
    totalMoney = loadSave.getMoney();
    dayCounter = loadSave.getDays();

  };

  // Allows the user to enter a desired name for the store.
  if (save == 0) {
    std::cout << "Please enter your store name:" << std::endl;
    std::cin >> storeName;
  };
  std::cout << std::endl;

  // Create the inventory object with totalMoney as the parameter. 
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

  // Initialise a while loop which runs while the store rating is >= 0.5 and the money is greater than 0.
  while ((rating >= 0.5) && (hold.getMoney() > 0)) {
    
    // Tells player info about games state, (current inventory, day, money, etc.) 
    // and asks if any stock needs to be purchased.
    std::cout << storeName << " is now on Day " << dayCounter << std::endl;
    std::cout << "Your Current Money: $" << hold.getMoney() << std::endl;
    std::cout << "Your Current Rating: " << rating << std::endl;
    std::cout << "" << std::endl;

    std::cout << "Current Inventory:" << std::endl;
    hold.showproduceItems();
    hold.showdryItems();
    hold.showdairyItems();
    std::cout << "" << std::endl;

    hold.buyItemProduce();
    hold.buyItemDry();
    hold.buyItemDairy();

    // Shows the player the contents of their inventory.
    std::cout << "New Inventory:" << std::endl;
    hold.showproduceItems();
    hold.showdryItems();
    hold.showdairyItems();
    std::cout << "" << std::endl;

    // Asks the player if they want to hire an employee
    hold.hireEmployee();
    std::cout << "" << std::endl;
    std::cout << "Enter 0 to start the day" << std::endl;

    // Run the getValidInput function to validate user input.
    getValidInput(random, 0,0,0, "Please enter a valid value.");
    std::cout << std::endl;

    // Generate a random number of customers using the generateRandom function.
    int numCustomers = generateRandom(1, 2 * dayCounter + 1);

    // Use a for loop to create this random number of customers
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

      // Set the inventory money to current money + money that the customer has spent.
      hold.setMoney(hold.getMoney()+customer.getMoneySpent());

      std::cout << customer.getName() << ""
                << " bought " << customer.itemsBought() << " items"
                << std::endl;

      // Updates the store rating dependent on items bought.
      rating = customer.setRating(rating);
    };

    // Set the inventory money based on the number of employees multiplied by customers multiplied by 2.
    hold.setMoney(hold.getMoney()+(hold.getEmployeeCount() * numCustomers * 2));
    std::cout << std::endl;

    // Run functions to check which items have expired from inventory.
    std::cout << hold.checkProduceExpiry() << " Produce Items have Expired"
              << std::endl;
    std::cout << hold.checkDryExpiry() << " Dry Items have Expired"
              << std::endl;
    std::cout << hold.checkDairyExpiry() << " Dairy Items have Expired"
              << std::endl;
    std::cout << "" << std::endl;

    // Print current money and current rating.
    std::cout << "Current Money:" << hold.getMoney() << std::endl;

    rating = roundToNDecimalPlaces(rating + (hold.getEmployeeCount() * 0.2), 2);
    std::cout << "Current Rating:" <<  rating << std::endl;
    std::cout << "" << std::endl;

    std::cout << "You have Finished Day " << dayCounter << std::endl;
    std::cout << std::endl;
    std::cout << "Enter 0 to Continue" << std::endl;

    // Input validation
    getValidInput(choice, 0,0,0, "Please enter a valid value.");
    std::cout << std::endl;

    //Increment day by one and reset the employees at the store.
    dayCounter = dayCounter + 1;
    hold.resetEmployee();

    // Ask the user whether they want to save game
    std::cout << "Do you want to save now?" << std::endl;
    std::cout << "Yes (1) or No (0)" << std::endl;

    // Input validation
    getValidInput(saveNow, 0,0,1, "Please enter a valid number (1 for Yes, 0 for No)");
    std::cout << std::endl;  

    // If user decides to savegame, run the appropriate functions and let the user know. 
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

  // Inventory money check, if lower than or equal to 0, game ends. 
  if (hold.getMoney() <= 0) {
    system("clear");
    std::cout << "Game Over" << std::endl;
    std::cout << "Your store when bankrupt and had to close!" << std::endl;
    std::cout << "Better Luck Next Time" << std::endl;
  }

  return 0;
}