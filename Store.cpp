#include "Store.h"
#include <iostream>

using namespace std;

Store::Store(){
    name = ' ';
    days = 0;
    rating = 0;
    inventory = nullptr;
    customers = nullptr;
    employees = nullptr;
}

Store::Store(string _name, int _days, double _rating, Inventory* _inventory, Customer* _customers, Employee* _employees){
    name = _name;
    days = _days;
    rating = _rating;   
    inventory = _inventory;
    customers = _customers;
    employees = _employees;
}

void Store::getInventory(){
    int length = sizeof(inventory)/sizeof(employees[0]);
    for (int i = 0; i < length; i++){
        std::cout << inventory[i] << std::endl;  ------>> // GET NAME OF EMPLOYEE FROM CLASS
    }
}

void Store::getCustomers(){
    int length = sizeof(customers)/sizeof(customers[0]);
    for (int i = 0; i < length; i++){
        std::cout << customers[i] << std::endl;  ------>> // GET NAME OF EMPLOYEE FROM CLASS
    }
}

void Store::getEmployees(){
    int length = sizeof(employees)/sizeof(employees[0]);
    for (int i = 0; i < length; i++){
        std::cout << employees[i] << std::endl;  ------>> // GET NAME OF EMPLOYEE FROM CLASS
    }
}

string Store::getName(){
    return name;
}

int Store::getDays(){
    return days;
}

double Store::getRating(){
    return rating;
}
