#include"Headers.h"
#include<iostream>
using namespace std;
#include <string>

int main(){
    string names[60] = {"Ila", "Gunner","Stevie","Kevin","Cali","Drew","Paris","Roman","Giselle",
    "Uriel","Magnolia","Orion","Elena","Kairo","Aubriella","Cash","Grace","Keegan","Mary","Elliot","Denver",
    "Alex","Saige","Kamryn","Rayne","Harlem","Mya","Isaiah","Sophia","Cyrus","Katherine","Finn","Leila",
    "John","Mina","Joel","Anahi","Corey","Amayah","Archie","Cadence","Rex","Ainhoa","Kylan","Melina","Jacoby",
    "Ruby","Robert","Kai","Roy","Sevyn","Madden","Dalayza","Felipe","Magnolia","Collin","Lennox","Braylen","Winnie","Connor"}; 
    int day = 1;
    Inventory inventory(1000);
    customers = new Customer[30];
    for (int i = 0; i<30; i++){
        customers[i] = Customer(names[i]);
    }
    for (int k = 0; k<30; k++){
        cout<< customers[k].getName()<<endl;
    }
    //Store store();
    cout << "You're store begins with " <<inventory.getMoney()<<" dollars"<<endl;
    

}