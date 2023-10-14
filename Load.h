#include <string>
#include <iostream>
#include <fstream>
using namespace std;
ifstream inputfile;
class Load{
    private:
        string name;
        int produceItems;
        int dairyItems;
        int dryItems;
        int apple;
        int banana;
        int carrot;
        int cheese;
        int milk; 
        int yoghurt;
        int biscuit;
        int bread;
        int chocolate;
        double money;
        double rating;
        string var;
        int days;
        int employees;
    public:
        Load(){
            inputfile.open("save.txt");
            getline(inputfile,name);
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
            getline(inputfile, var);
            employees = stoi(var);
            
           
        }
        string getName(){return name;}
        int getProduceItems() {return produceItems;}
        int getDairyItems() {return dairyItems;}
        int getDryItems() {return dryItems;}
        int getApple() {return apple;}
        int getBanana() {return banana;}
        int getCarrot() {return carrot;}
        int getCheese() {return cheese;}
        int getMilk() {return milk;}
        int getYoghurt() {return yoghurt;}
        int getBiscuit() {return biscuit;}
        int getBread() {return bread;}
        int getChocolate() {return chocolate;}
        double getMoney() {return money;}
        double getRating() {return rating;}
        int getDays() {return days;}
        int getEmployees() {return employees;}

};