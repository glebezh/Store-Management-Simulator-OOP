#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

#include "Inventory.h"
#include "Person.h"
#include "Random.h"

class Employee : public Person {
 private:
  double wageCost;
  double tipCost;

 public:
  Employee(){};
  Employee(string _name):Person(_name){
     wageCost = generateRandom(2,6);
     tipCost = generateRandom(0,3);
  };
  void drawWage(Inventory& inventory){
    inventory.setMoney(inventory.getMoney() - wageCost + tipCost);
  }

  double getwageCost(){return wageCost;};
  double gettipCost(){return tipCost;}


  void setName() {
    std::vector<std::string> names = {
        "Ila",      "Gunner", "Stevie",    "Kevin",   "Cali",     "Drew",
        "Paris",    "Roman",  "Giselle",   "Uriel",   "Magnolia", "Orion",
        "Elena",    "Kairo",  "Aubriella", "Cash",    "Grace",    "Keegan",
        "Mary",     "Elliot", "Denver",    "Alex",    "Saige",    "Kamryn",
        "Rayne",    "Harlem", "Mya",       "Isaiah",  "Sophia",   "Cyrus",
        "Katherine", "Finn",   "Leila",     "John",    "Mina",     "Joel",
        "Anahi",     "Corey",  "Amayah",    "Archie",  "Cadence",  "Rex",
        "Ainhoa",    "Kylan",  "Melina",    "Jacoby",  "Ruby",     "Robert",
        "Kai",       "Roy",    "Sevyn",     "Madden",  "Dalayza",  "Felipe",
        "Madeline",  "Collin", "Lennox",    "Braylen", "Winnie",   "Connor"};

    name = (names[generateRandom(0, names.size() - 1)]);
    ;
  }
};

#endif