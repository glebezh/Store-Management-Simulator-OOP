
#include <fstream>

#include "Inventory.h"
using namespace std;
ofstream myfile;
void saveGame(Inventory inven, int days, double rating, string name) {
  myfile.open("save.txt");
  myfile << name << endl;
  myfile << to_string(days) << endl;
  myfile << to_string(rating) << endl;
  myfile << to_string(inven.getMoney()) << endl;

  // saving produce
  int produceCount = inven.getProduceCounter();
  myfile << to_string(produceCount) << endl;
  int apples = 0;
  int bananas = 0;
  int carrots = 0;
  vector<Item*> produce = inven.getProduceItems();
  for (int i = 0; i < produceCount; i++) {
    if (produce[i]->getName() == "Apple") {
      apples++;
    }
    if (produce[i]->getName() == "Banana") {
      bananas++;
    }
    if (produce[i]->getName() == "Carrot") {
      carrots++;
    }
  }
  myfile << to_string(apples) << endl;
  myfile << to_string(bananas) << endl;
  myfile << to_string(carrots) << endl;

  // saving dairy
  int dairyCount = inven.getDairyCounter();
  myfile << to_string(dairyCount) << endl;
  int cheese = 0;
  int milk = 0;
  int yoghurt = 0;
  vector<Item*> dairy = inven.getDairyItems();
  for (int i = 0; i < dairyCount; i++) {
    if (dairy[i]->getName() == "Cheese") {
      cheese++;
    }
    if (dairy[i]->getName() == "Milk") {
      milk++;
    }
    if (dairy[i]->getName() == "Yoghurt") {
      yoghurt++;
    }
  }
  myfile << to_string(cheese) << endl;
  myfile << to_string(milk) << endl;
  myfile << to_string(yoghurt) << endl;

  // saving dry
  int dryCount = inven.getDryCounter();
  myfile << to_string(dryCount) << endl;
  int biscuit = 0;
  int bread = 0;
  int chocolate = 0;
  vector<Item*> dry = inven.getDryItems();
  for (int i = 0; i < dryCount; i++) {
    if (dry[i]->getName() == "Biscuit") {
      biscuit++;
    }
    if (dry[i]->getName() == "Bread") {
      bread++;
    }
    if (dry[i]->getName() == "Chocolate") {
      chocolate++;
    }
  }
  myfile << to_string(biscuit) << endl;
  myfile << to_string(bread) << endl;
  myfile << to_string(chocolate) << endl;

  int empCount = inven.getEmployeeCount();
  myfile << to_string(empCount);

  myfile.close();
}
