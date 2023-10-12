#include"Headers.h"
#include<iostream>
using namespace std;
#include <string>
#include <vector>


int main(){
    Inventory inventory(100);
    string names[60] = {"Ila", "Gunner","Stevie","Kevin","Cali","Drew","Paris","Roman","Giselle",
    "Uriel","Magnolia","Orion","Elena","Kairo","Aubriella","Cash","Grace","Keegan","Mary","Elliot","Denver",
    "Alex","Saige","Kamryn","Rayne","Harlem","Mya","Isaiah","Sophia","Cyrus","Katherine","Finn","Leila",
    "John","Mina","Joel","Anahi","Corey","Amayah","Archie","Cadence","Rex","Ainhoa","Kylan","Melina","Jacoby",
    "Ruby","Robert","Kai","Roy","Sevyn","Madden","Dalayza","Felipe","Madeline","Collin","Lennox","Braylen","Winnie","Connor"}; 
    int day = 1;
    
    vector<Customer*> customers;
    for (int i = 0; i<30; i++){
        customers.push_back(new Customer(names[i]));
    }
    Store store();
    cout << "You're store begins with " <<inventory.getMoney()<<" dollars"<<endl;
    inventory.buyItemProduce();
    inventory.buyItemDairy();
    inventory.buyItemDry();

}