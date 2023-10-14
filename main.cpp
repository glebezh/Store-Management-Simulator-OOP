#include <iostream>
#include <string>
#include <vector>
#include "Headers.h"
using namespace std;

extern void saveGame(Inventory inven, int days, double rating, string name);

int main() {
  string storeName = "";

  double starting_money = 100.0;
  Inventory inventory(starting_money);

  string names[60] = {
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
  // load call happens here, if statement and if not we create a fresh inventory
  //  only inventory and store amount values matter, we can generate fresh customers
  //  and employees every time

  int day = 1;

  vector<Customer*> customers;
  for (int i = 0; i < 5; i++) {  // get rid of magic value
    customers.push_back(new Customer(names[i]));
    std::cout << customers[i]->getDesiredItem1();
    std::cout << customers[i]->getDesiredItem2();
    std::cout << customers[i]->getDesiredItem3();
  }

  vector<Employee*> employees;
  for (int i = 0; i < 30; i++) {
    employees.push_back(new Employee(names[60 - i - 1]));
  }

  cout << "Welcome Please Enter Store Name:" << endl;
  cin >> storeName;

  // Store store;
  cout << "Your store begins with " << inventory.getMoney() << " dollars"
       << endl;

  inventory.buyItemProduce();
  inventory.buyItemDairy();
  inventory.buyItemDry();
  saveGame(inventory);
  inventory.removeItem("Apple");
  inventory.showproduceItems();
}