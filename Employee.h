#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

#include "Inventory.h"
#include "Person.h"
#include "Random.h"
// class containing information for Employee object

class Employee : public Person {
 private:
  double wageCost;
  double tipCost;

 public:
 //constructors
  Employee(){};
  Employee(string _name):Person(_name){
     wageCost = 10;
     tipCost = 2;
  };
  //get functions
  double getWage() { return wageCost; };

  double getTip() { return tipCost; };

  void drawWage(Inventory& inventory){
    inventory.setMoney(inventory.getMoney() - wageCost + tipCost);
  }

  //potentials name lists
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