#include <iostream>

#include "Customer.h"
#include "Inventory.h"
#include "Random.h"

int main() {
  initRandom();
  srand(time(0));
  int dayCounter = 1;
  double totalMoney = 100;
  double rating = 3;
  int choice = 0;

  while ((rating > 0.5) && (totalMoney > 0)) {
    system("clear");
    std::cout << "Day " << dayCounter << std::endl;
    std::cout << "Your Current Money: $" << totalMoney << std::endl;
    std::cout << "Your Current Rating: " << rating << std::endl;
    int numCustomers = generateRandom(1, 2 * dayCounter + 1);

    Inventory hold(totalMoney);

    hold.buyItemProduce();
    hold.buyItemDry();
    hold.buyItemDairy();
    hold.showproduceItems();
    hold.showdryItems();
    hold.showdairyItems();

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

      std::cout << customer.getName() << " " << i + 1 << " bought "
                << customer.itemsBought() << " items" << std::endl;

      rating = customer.setRating(rating);
    };
    std::cout << hold.checkProduceExpiry() << " Produce Items have Expired"
              << std::endl;
    std::cout << hold.checkDryExpiry() << " Dry Items have Expired"
              << std::endl;
    std::cout << hold.checkDairyExpiry() << " Dairy Items have Expired"
              << std::endl;

    std::cout << "You have Finished Day " << dayCounter << std::endl;
    std::cout << "Enter 0 to Continue" << std::endl;
    std::cin >> choice;
    dayCounter = dayCounter + 1;
  };

  return 0;
}