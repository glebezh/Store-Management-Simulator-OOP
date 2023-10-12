#include <cstdlib>
#include <ctime>

inline void initRandom() { srand(time(0)); }

inline int generateRandom(int min, int max) {
  return rand() % (max - min + 1) + min;
}

std::string generateRandomItem(std::string items[], int size) {
    if (size <= 0) {
        return "";  
    }
    else{
      int randomIndex = std::rand() % size;
      string requiredItem = items[randomIndex];
      return requiredItem;
    }
}