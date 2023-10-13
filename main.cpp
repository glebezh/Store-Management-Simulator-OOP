#include <iostream>
#include <string>
#include <vector>
#include "Headers.h"
using namespace std;

extern void saveGame(Inventory inven, int days, double rating, string name);

int main(){
    int days = 0;
    double rating = 3;
    string storeName = "";
    bool load_save_choice = false;

  double starting_money = 100.0;
  Inventory inventory(starting_money);

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
        "Madeline",  "Collin", "Lennox",    "Braylen", "Winnie",   "Connor"
    };

    //load call happens here, if statement and if not we create a fresh inventory
    // only inventory and store values matter, we can generate fresh customers and employees every time

    cout << "Before we start the application, would you like to load in a save?" << endl;
    cin >> load_save_choice;

    if (load_save_choice == true){
        //load_save function here
    }

    cout << "Welcome to the Store Running Simulator application. Please Enter Store Name:" << endl;
    cin >> storeName;

    int day = 1;

    bool continueLoop = true;

    while(inventory.getMoney() > 0 && continueLoop){

        if (day >= 1){
            std::cout << "In your inventory you have the following produce items" << std::endl;
            inventory.showproduceItems();
            inventory.showdairyItems();
            inventory.showdryItems();
        }

        //show expiry ===== quick sell option

        std::cout << "Day:" << day << std::endl;
        cout << "Your store begins with " <<inventory.getMoney()<<" dollars"<<endl;

        

        vector<Customer*> customers;
        int number_customers = generateRandom(5, 10);
        for (int i = 0; i<number_customers; i++){ //get rid of magic value
            string name = names[generateRandom(0, names.size() - 1)];
            customers.push_back(new Customer(name));
        }

        vector<Employee*> employees;
        int number_employees = generateRandom(5, 10);
        for (int i = 0; i<number_employees; i++){
            string name = names[generateRandom(0, names.size() - 1)];
            employees.push_back(new Employee(name));
        }

        inventory.buyItemProduce();
        inventory.buyItemDairy();
        inventory.buyItemDry();
        saveGame(inventory, days, rating, storeName);


        // inventory.removeItem("Apple");
        // inventory.showproduceItems();

        for (int i = 0; i <number_customers;i++){
            customers[i]->buyFromInventory1(inventory);
            customers[i]->buyFromInventory2(inventory);
            customers[i]->buyFromInventory3(inventory);
        }

        for (int i = 0; i < number_employees; i++){
            if (inventory.getMoney() > (employees[i]->getwageCost() - employees[i]->gettipCost())){
                employees[i]->drawWage(inventory);
            }
            else{
                std::cout << "You do not have enough money to pay " << employees[i]->getName() << ". You have gone bankrupt!" << std::endl;
                continueLoop = false;
                break;
            }
        }


        inventory.checkDairyExpiry();
        inventory.checkDryExpiry();
        inventory.checkProduceExpiry();

        day+=1;

        

    }

    return 0;
}
