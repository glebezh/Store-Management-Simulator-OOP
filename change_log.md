# Changelog

All notable changes to this project will be documented in this file.


Version [13-10-2023]
- Removed the store class. As a group we decided that the properties of the class can simply be specified in the main.cpp file, and that realistically the inventory class would be able to achieve all of the  goals of the store class.


Version [11-10-2023]
- Implemented the expiry property for the item class. This was done in order to make the game more realistic. 

Version [10-10-2023]
- Removed the grabItems functions from the Person class. This function will only be relevant for customers (not employees) and hence should be included in the inherited class, not the base class.


