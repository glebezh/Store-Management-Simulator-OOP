#ifndef STORE_H
#define STORE_H

using namespace std;

#include <string>
#include "Inventory.h"
#include "Customer.h"
#include "Employee.h"
#include <iostream>


class Store{
    private:
        string name;
        int days;
        double rating;
        Inventory* inventory;
        Customer* customers;
        Employee* employees;
    public:
        // Constructors
        Store();
        Store(string _name, int _days, double _rating, Inventory* _inventory, Customer* _customers, Employee* _employees);

        // Methods/Functions
        void getInventory();
        void getCustomers();
        void getEmployees();
        string getName();
        int getDays();
        double getRating();
};


#endif