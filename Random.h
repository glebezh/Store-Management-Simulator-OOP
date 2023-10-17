#ifndef RANDOM_
#define RANDOM_H

#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <cmath>


#pragma once 

// randomiser

inline void initRandom() { srand(time(0)); }

inline int generateRandom(int min, int max) {
  return rand() % (max - min + 1) + min;
}

inline double roundToNDecimalPlaces(double number, int decimalPlaces) {
    double multiplier = std::pow(10.0, decimalPlaces);
    return std::round(number * multiplier) / multiplier;
}


#endif


// inline void getValidInput(int variable, std::string prompt) {
//     while (true) {
//         std::cin >> variable;
//          if (std::cin.good() && (variable == 0 || variable == 1)) {
//             break; 
//         } else {
//             std::cin.clear();
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//             std::cout << "Please enter a valid value." << std::endl;
//         }
//     }
// }


//     while (true) {
//       std::cin >> choice;
//       if (std::cin.good() && (choice == 0 || choice == 1)) {
//         break;
//       } else {
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits<int>::max(), '\n');
//         std::cout << "Please enter a valid number (1 for Yes, 0 for No)" << std::endl;
//       }
//     }


 

// inline std::string generateRandomItem(std::vector<std::string>& stringArray) {
//     int size = stringArray.size(); 
//     if (size <= 0) {
//         return "";
//     } else {
//         int randomIndex = std::rand() % size;
//         std::string requiredItem = stringArray[randomIndex]; 
//         return requiredItem;
//     }
// }