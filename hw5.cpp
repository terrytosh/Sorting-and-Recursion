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

MergeSort():

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
  int i = l, j = mid + 1; //i is for left-hand,j is for right-hand
  int k = 0; //k is for the temporary array
  while(i <= mid && j <= r){
    if(vec[i].compare(vec[j]) <= 0)
        temp[k++] = vec[i++];
    else
        temp[k++] = vec[j++];
    }
    //rest elements of left-half
    while(i <= mid)
        temp[k++] = vec[i++];
    //rest elements of right-half
    while(j <= r)
        temp[k++] = vec[j++];
    //copy the mergered temporary array to the original array
    for(k = 0, i = l; i <= r; ++i, ++k)
        vec[i] = temp[k];
 
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