#include "Store.h"

Store::Store(){
    name = ' ';
    days = 0;
    rating = 0;

}

Store::Store(string _name, int _days, double _rating){
    name = _name;
    days = _days;
    rating = _rating;   
}

void Store::getInventory(){
}

void Store::getCustomers(){
}

void Store::getEmployees(){
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
