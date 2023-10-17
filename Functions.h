#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <cmath>

//Function to set the seed.
inline void initRandom() { srand(time(0)); }

// Function to generate a random value within a range.
inline int generateRandom(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to round a number to n decimal places.
inline double roundToNDecimalPlaces(double number, int decimalPlaces) {
    double multiplier = std::pow(10.0, decimalPlaces);
    return std::round(number * multiplier) / multiplier;
}

// Function to verify user input.
inline void getValidInput(int& variable, int required_choice1, int required_choice2, int required_choice3, std::string prompt) {
  while (true) {
    std::cin >> variable;
      if (std::cin.good() && (variable == required_choice1 || variable == required_choice2 || variable == required_choice3)){
        break; 
      } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << prompt << std::endl;
      }
  }
}

#endif
