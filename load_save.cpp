
#include "Inventory.h"
#include <fstream>
using namespace std;
ofstream myfile;
void saveGame(Inventory inven, int days, double rating, string name){
    myfile.open("save.txt");
    myfile << name<<endl;
    myfile << days<<endl;
    myfile << rating<<endl;
    myfile << inven.getMoney()<<endl;

    //saving produce
    int produceCount = inven.getProduceCounter();
    myfile << produceCount <<endl;
    int apples = 0;
    int bananas = 0;
    int carrots = 0;
    vector<Item*> produce = inven.getProduceItems();
    for (int i = 0; i<produceCount; i++){
        
        if (produce[i]->getName() == "Apple"){
            apples++;
            
        }
         if (produce[i]->getName() =="Banana"){
            bananas++;
        }
         if (produce[i]->getName() =="Carrot"){
            carrots++;
        }
        
    }
    myfile << apples<<endl;
    myfile << bananas<<endl;
    myfile << carrots<<endl;

    //saving dairy
    int dairyCount = inven.getDairyCounter();
    myfile << dairyCount <<endl;
    int cheese = 0;
    int milk = 0;
    int yoghurt = 0;
    vector<Item*> dairy = inven.getDairyItems();
    for (int i = 0; i<dairyCount; i++){
        
        if (dairy[i]->getName() == "Cheese"){
            cheese++;
            
        }
         if (dairy[i]->getName() =="Milk"){
            milk++;
        }
         if (dairy[i]->getName() =="Yoghurt"){
            yoghurt++;
        }
        
    }
    myfile << cheese<<endl;
    myfile << milk<<endl;
    myfile << yoghurt<<endl;

    //saving dry
    int dryCount = inven.getDryCounter();
    myfile << dryCount <<endl;
    int biscuit = 0;
    int bread = 0;
    int chocolate = 0;
    vector<Item*> dry = inven.getDryItems();
    for (int i = 0; i<dryCount; i++){
        
        if (dry[i]->getName() == "Biscuit"){
            biscuit++;
            
        }
         if (dry[i]->getName() =="Bread"){
            bread++;
        }
         if (dry[i]->getName() =="Chocolate"){
            chocolate++;
        }
        
    }
    myfile << biscuit<<endl;
    myfile << bread<<endl;
    myfile << chocolate<<endl;
    


    myfile.close();
}