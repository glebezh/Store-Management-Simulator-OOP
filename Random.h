#include <cstdlib>
#include <ctime>

inline void initRandom() { srand(time(0)); }

inline int generateRandom(int min, int max) {
  return rand() % (max - min + 1) + min;
}
