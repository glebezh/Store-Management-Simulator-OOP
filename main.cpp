#include <iostream>

#include "Headers.h"
using namespace std;
#include <string>
#include <vector>


int main(){

    string storeName = "";

    double starting_money = 100.0;
    Inventory inventory(starting_money);

    string names[60] = {"Ila", "Gunner","Stevie","Kevin","Cali","Drew","Paris","Roman","Giselle",
    "Uriel","Magnolia","Orion","Elena","Kairo","Aubriella","Cash","Grace","Keegan","Mary","Elliot","Denver",
    "Alex","Saige","Kamryn","Rayne","Harlem","Mya","Isaiah","Sophia","Cyrus","Katherine","Finn","Leila",
    "John","Mina","Joel","Anahi","Corey","Amayah","Archie","Cadence","Rex","Ainhoa","Kylan","Melina","Jacoby",
    "Ruby","Robert","Kai","Roy","Sevyn","Madden","Dalayza","Felipe","Madeline","Collin","Lennox","Braylen","Winnie","Connor"}; 
    int day = 1;
    
    vector<Customer*> customers;
    for (int i = 0; i<30; i++){ //get rid of magic value
        customers.push_back(new Customer(names[i]));
    }

    vector<Employee*> employees;
    for (int i = 0; i<30; i++){
        employees.push_back(new Employee(names[60-i-1]));
    }

    cout << "Welcome Please Enter Store Name:" << endl;
    cin >> storeName;

    // Store store;
    cout << "Your store begins with " <<inventory.getMoney()<<" dollars"<<endl;

    inventory.buyItemProduce();
    inventory.buyItemDairy();
    inventory.buyItemDry();

    inventory.removeItem("Apple");
    inventory.showproduceItems();



}