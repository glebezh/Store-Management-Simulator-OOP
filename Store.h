#ifndef STORE_H
#define STORE_H

using namespace std;

#include <string>
#include "Customer.h"
#include "Inventory.h"
#include "Employee.h"
#include <iostream>


class Store{
    protected:
        string name;
        int days;
        double rating;
        Customer* customers;
        Inventory* inventory;
        Employee* employees;
    public:
        // Constructors
        Store();
        Store(string _name, int _days, Inventory* _inventory, 
        Customer* _customers, Employee* _employees);

        // Methods/Functions
        void getInventory();
        void getCustomers();
        void getEmployees();
        string getName();
        int getDays();
        double getRating();
};


#endif
