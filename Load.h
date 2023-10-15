#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
ifstream inputfile;
class Load {
 private:
  string name = "";
  int produceItems = 0;
  int dairyItems = 0;
  int dryItems = 0;
  int apple = 0;
  int banana = 0;
  int carrot = 0;
  int cheese = 0;
  int milk = 0;
  int yoghurt = 0;
  int biscuit = 0;
  int bread = 0;
  int chocolate = 0;
  double money = 0;
  double rating = 0;
  string var = "";
  int days = 0;

 public:
  Load() {
    inputfile.open("save.txt");
    getline(inputfile, name);
    getline(inputfile, var);
    days = stoi(var);
    getline(inputfile, var);
    rating = stod(var);
    getline(inputfile, var);
    money = stod(var);
    getline(inputfile, var);
    produceItems = stoi(var);
    getline(inputfile, var);
    apple = stoi(var);
    getline(inputfile, var);
    banana = stoi(var);
    getline(inputfile, var);
    carrot = stoi(var);
    getline(inputfile, var);
    dairyItems = stoi(var);
    getline(inputfile, var);
    cheese = stoi(var);
    getline(inputfile, var);
    milk = stoi(var);
    getline(inputfile, var);
    yoghurt = stoi(var);
    getline(inputfile, var);
    dryItems = stoi(var);
    getline(inputfile, var);
    biscuit = stoi(var);
    getline(inputfile, var);
    bread = stoi(var);
    getline(inputfile, var);
    chocolate = stoi(var);
    inputfile.close();
  }
  Load(int n) {
    if (n == 1) {
      inputfile.open("save.txt");
      getline(inputfile, name);
      getline(inputfile, var);
      days = stoi(var);
      getline(inputfile, var);
      rating = stod(var);
      getline(inputfile, var);
      money = stod(var);
      getline(inputfile, var);
      produceItems = stoi(var);
      getline(inputfile, var);
      apple = stoi(var);
      getline(inputfile, var);
      banana = stoi(var);
      getline(inputfile, var);
      carrot = stoi(var);
      getline(inputfile, var);
      dairyItems = stoi(var);
      getline(inputfile, var);
      cheese = stoi(var);
      getline(inputfile, var);
      milk = stoi(var);
      getline(inputfile, var);
      yoghurt = stoi(var);
      getline(inputfile, var);
      dryItems = stoi(var);
      getline(inputfile, var);
      biscuit = stoi(var);
      getline(inputfile, var);
      bread = stoi(var);
      getline(inputfile, var);
      chocolate = stoi(var);
      inputfile.close();
    }

    if (n == 2) {
      inputfile.open("save2.txt");
      getline(inputfile, name);
      getline(inputfile, var);
      days = stoi(var);
      getline(inputfile, var);
      rating = stod(var);
      getline(inputfile, var);
      money = stod(var);
      getline(inputfile, var);
      produceItems = stoi(var);
      getline(inputfile, var);
      apple = stoi(var);
      getline(inputfile, var);
      banana = stoi(var);
      getline(inputfile, var);
      carrot = stoi(var);
      getline(inputfile, var);
      dairyItems = stoi(var);
      getline(inputfile, var);
      cheese = stoi(var);
      getline(inputfile, var);
      milk = stoi(var);
      getline(inputfile, var);
      yoghurt = stoi(var);
      getline(inputfile, var);
      dryItems = stoi(var);
      getline(inputfile, var);
      biscuit = stoi(var);
      getline(inputfile, var);
      bread = stoi(var);
      getline(inputfile, var);
      chocolate = stoi(var);
      inputfile.close();
    }
  }
  string getName() { return name; }
  int getProduceItems() { return produceItems; }
  int getDairyItems() { return dairyItems; }
  int getDryItems() { return dryItems; }
  int getApple() { return apple; }
  int getBanana() { return banana; }
  int getCarrot() { return carrot; }
  int getCheese() { return cheese; }
  int getMilk() { return milk; }
  int getYoghurt() { return yoghurt; }
  int getBiscuit() { return biscuit; }
  int getBread() { return bread; }
  int getChocolate() { return chocolate; }
  double getMoney() { return money; }
  double getRating() { return rating; }
  int getDays() { return days; }

  std::vector<std::string> getProduce() {
    std::vector<std::string> produceItems;
    for (int i = 0; i < apple; i++) {
      produceItems.push_back("Apple");
    }
    for (int i = 0; i < banana; i++) {
      produceItems.push_back("Banana");
    }
    for (int i = 0; i < carrot; i++) {
      produceItems.push_back("Carrot");
    }
    return produceItems;
  }
  std::vector<std::string> getDry() {
    std::vector<std::string> dryItems;
    for (int i = 0; i < biscuit; i++) {
      dryItems.push_back("Biscuit");
    }
    for (int i = 0; i < bread; i++) {
      dryItems.push_back("Bread");
    }
    for (int i = 0; i < chocolate; i++) {
      dryItems.push_back("Chocolate");
    }
    return dryItems;
  }
  std::vector<std::string> getDairy() {
    std::vector<std::string> dairyItems;
    for (int i = 0; i < cheese; i++) {
      dairyItems.push_back("Cheese");
    }
    for (int i = 0; i < milk; i++) {
      dairyItems.push_back("Milk");
    }
    for (int i = 0; i < yoghurt; i++) {
      dairyItems.push_back("Yoghurt");
    }
    return dairyItems;
  }

  std::vector<std::string> getLoadedProduce() { return getProduce(); }
  std::vector<std::string> getLoadedDry() { return getDry(); }
  std::vector<std::string> getLoadedDairy() { return getDairy(); }
};