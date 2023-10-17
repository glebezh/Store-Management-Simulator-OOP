// This tests the functionality of the all Classes and functions except saving
// This test acts a shell for the final code

// To run this test use:
//  g++ test.cpp Item.cpp Inventory.cpp -o "test"
// ./test

#include <iostream>

#include "Customer.h"
#include "Employee.h"
#include "Inventory.h"
#include "Random.h"

int main() {
  initRandom();
  srand(time(0));

  // Initializes the store settings
  int dayCounter = 1;
  double totalMoney = 100;
  double rating = 3;
  int choice = 0;
  int random = 0;

  // Creates an Inventory
  Inventory hold(totalMoney);

  // While loop will determine when the game ends
  while ((rating > 0.5) && (totalMoney > 0)) {
    system("clear");
    // Displays the current values
    std::cout << "Day " << dayCounter << std::endl;
    std::cout << "Your Current Money: $" << totalMoney << std::endl;
    std::cout << "Your Current Rating: " << rating << std::endl;
    // Generates a random number of customers based on the number of days
    int numCustomers = generateRandom(1, 2 * dayCounter + 1);
    std::cout << "" << std::endl;
    // Displays the Inventory
    std::cout << "Current Inventory:" << std::endl;
    hold.showproduceItems();
    hold.showdryItems();
    hold.showdairyItems();
    std::cout << "" << std::endl;

    // Allows the player to purchase items
    hold.buyItemProduce();
    hold.buyItemDry();
    hold.buyItemDairy();

    // Displays new Inventory
    std::cout << "New Inventory:" << std::endl;
    hold.showproduceItems();
    hold.showdryItems();
    hold.showdairyItems();
    std::cout << "" << std::endl;

    // Allows the player to hire employees
    hold.hireEmployee();
    std::cout << "" << std::endl;
    std::cout << "Enter 0 to start the day" << std::endl;
    std::cin >> random;
    if (random != 0) {
      std::cout << "Please enter a valid number" << std::endl;
      std::cout << "Enter 0 to start the day" << std::endl;
      std::cin >> random;
    }

    // Generates the customers items and allows them to remove items from
    // inventory
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
      customer.setDesiredItem1(items[generateRandom(0, items.size() - 1)]);
      customer.setDesiredItem2(items[generateRandom(0, items.size() - 1)]);
      customer.setDesiredItem3(items[generateRandom(0, items.size() - 1)]);

      customer.buyFromInventory1(hold);
      customer.buyFromInventory2(hold);
      customer.buyFromInventory3(hold);
      totalMoney = totalMoney + customer.getMoneySpent();
      totalMoney = totalMoney + (hold.getEmployeeCount() * numCustomers * 2);

      std::cout << customer.getName() << " "
                << " bought " << customer.itemsBought() << " items"
                << std::endl;

      rating = customer.setRating(rating);
    };
    std::cout << hold.checkProduceExpiry() << " Produce Items have Expired"
              << std::endl;
    std::cout << hold.checkDryExpiry() << " Dry Items have Expired"
              << std::endl;
    std::cout << hold.checkDairyExpiry() << " Dairy Items have Expired"
              << std::endl;

    std::cout << "" << std::endl;
    // Displays the new store values
    std::cout << "Current Money:" << totalMoney << std::endl;

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
  };
  // Displays when while loop breaks
  std::cout << "Game Over" << std::endl;

  if (rating < 0.5) {
    std::cout << "Your store had an abysmal rating and had to close!"
              << std::endl;
    std::cout << "Better Luck Next Time" << std::endl;
  }

  if (totalMoney < 0) {
    std::cout << "Your store when bankrupt and had to close!" << std::endl;
    std::cout << "Better Luck Next Time" << std::endl;
  }
  return 0;
}