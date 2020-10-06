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

InsertionSort():
Base case - once index <= 1 return.
Recrusively call insertHelper(vec, index - 1) to 
sort index - 1 elements. Store last element in end = vec[index - 1]
and the current_index as index - 2. Move elements position in
vector up by one, if they are greater than end. Set vec[current_index + 1] = end;

MergeSort():
Base case - if left index >= right index return.
Recuresively call mergeHelper(vec, l, mid) to break the left
side down into single vectors to be built back up. And recursively call mergeHelper(vec, mid + 1, r) to do the same to the right side of the vector. Then once all the mergeHelper calls have finished, call merge(vec, l, mid, r) to sort the subarrays into alphabetical order. 
Dynamically allocate a new array of strings for temp use.
Initialiaze i to be the left index, mid+1 to be the right index,
k to be the temp array index. While i index hasn't reached the middle
&& the left index hasn't reach the end, compare the elements at
the current positions of the subarrays. If vec[i] comes before vec[j],
add vec[i] to the temp array and incement both i and k; Else, add vec[j] to the temp array and increment k and j. After, run two while loops to put the rest of the elements in the left side of the vector and the right side into the temp array. Finally, put the elements of temp into the vector to sort it. Delete temp [].
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

void merge(std::vector<std::string> &vec, int l, int mid, int r) {
  std::string *temp = new std::string[r - l + 1];
  int i = l;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= r) {
    if (vec[i].compare(vec[j]) <= 0) {
      temp[k++] = vec[i++];
    } else {
      temp[k++] = vec[j++];
    }
  }

    while (i <= mid) {
      temp[k++] = vec[i++];
    }
    while (j <= r) {
      temp[k++] = vec[j++];
    }

    for(k = 0, i = l; i <= r; ++i, ++k){
      vec[i] = temp[k];
    }

  delete []temp; 
}

void mergeHelper(std::vector<std::string> &vec, int l, int r) {
  int mid; 
  if (l < r) {
    mid = l + (r - l) / 2;
    mergeHelper(vec, l, mid);
    mergeHelper(vec, mid + 1, r);
    merge(vec, l, mid, r);
  }
}

void MergeSort(std::vector<std::string> &vec) {
  mergeHelper(vec, 0, vec.size() - 1);
}