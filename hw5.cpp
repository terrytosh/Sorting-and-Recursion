/*
-----Pseudocode-----
BubbleSort():
If vector has 0 or 1 element(s) return.
Initialiaze a temp string to act as a buffer
when swapping elements. Initialize a bool swapped
to store whether or not a pass contained a swap.
Do while(swapped), set swapped to false, interate from 0 to size - 1. If the current element comes alphabetically after its
proceeding element, swap them and set swapped = true. Keep doing this process for each element in the vector
until no elements are swapped or until i reaches size - 1.
*/
#include <vector>
#include <string>
#include "hw5.h"

void BubbleSort(std::vector<std::string> &vec) {
  if (vec.size() < 2) {
    return;
  }
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

void insertHelper(std::vector<int> &v, int index) {
  if (index <= 1) {
    return;
  }

  insertHelper(v, index - 1);
  int end = v[index - 1];
  int current_index = index - 2;

  while (current_index >= 0 && v[current_index] > end) { 
    v[current_index + 1] = v[current_index]; 
    current_index--; 
  }
  v[current_index + 1] = end; 
}

void InsertionSort(std::vector<int> &v) {
  insertHelper(v, v.size());
}