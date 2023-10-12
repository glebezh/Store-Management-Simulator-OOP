#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#pragma once

inline void initRandom() { srand(time(0)); }

inline int generateRandom(int min, int max) {
  return rand() % (max - min + 1) + min;
}

inline std::string generateRandomItem(std::vector<std::string>& stringArray) {
    int size = stringArray.size(); 
    if (size <= 0) {
        return "";
    } else {
        int randomIndex = std::rand() % size;
        std::string requiredItem = stringArray[randomIndex]; 
        return requiredItem;
    }
}

 