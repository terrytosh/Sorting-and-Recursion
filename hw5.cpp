/*
-----Pseudocode-----
*/
#include <vector>
#include <string>
#include <cassert>
#include "hw5.h"

void BubbleSort(std::vector<std::string> &vec) {
  assert(vec.size() > 1);
  std::string temp;
  bool swapped;

  do {
    swapped = false;
    for (int i = 0; i < vec.size() - 1; i++) {
      if (vec[i].compare(vec[i + 1]) > 0) {
        temp = vec[i];
        vec[i] = vec[i + 1];
        vec[i + 1] = temp;
        swapped = true;
      }
    }
  } while (swapped);
}