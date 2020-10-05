#include <iostream>
#include <vector>
#include "hw5.h"

void print(std::vector<std::string> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

void print(std::vector<int> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

int main() {
  //BubbleSort()
  //Test case 1
  std::vector<std::string> bubble_1;
  bubble_1 = {"ruth", "dora", "ziegellaub", "emma", "eichler"};
  std::cout << "Case 1: ";
  BubbleSort(bubble_1);
  print(bubble_1);
  std::cout << "Expected: [dora, eichler, emma, ruth, ziegellaub]" << std::endl;

  //Test case 2
  std::vector<std::string> bubble_2;
  bubble_2 = {"ruth"};
  std::cout << "Case 2: ";
  BubbleSort(bubble_2);
  print(bubble_2);
  std::cout << "Expected: [ruth]" << std::endl;

  //Test case 3
  std::vector<std::string> bubble_3;
  std::cout << "Case 3: ";
  BubbleSort(bubble_3);
  print(bubble_3);
  std::cout << "Expected: []" << std::endl;

  //InsertionSort()
  //Test case 1
  std::vector<int> insert_1;
  insert_1 = {10, 9, 8, 7, 6, 5};
  std::cout << "Case 1: ";
  InsertionSort(insert_1);
  print(insert_1);
  std::cout << "Expected: [5, 6, 7, 8, 9, 10]" << std::endl;

  //Test case 2
  std::vector<int> insert_2;
  insert_2 = {1};
  std::cout << "Case 2: ";
  InsertionSort(insert_2);
  print(insert_2);
  std::cout << "Expected: [1]" << std::endl;

  //Test case 3
  std::vector<int> insert_3;
  insert_3 = {-5, 10, -5, -4, 0, 0, 100};
  std::cout << "Case 3: ";
  InsertionSort(insert_3);
  print(insert_3);
  std::cout << "Expected: [-5, -5, -4, 0, 0, 10, 100]" << std::endl;

  //MargeSort()
  //Test case 1
  std::vector<std::string> merge_1;
  merge_1 = {"ruth", "dora", "ziegellaub", "emma", "eichler"};
  std::cout << "Case 1: ";
  MergeSort(merge_1);
  print(merge_1);
  std::cout << "Expected: [dora, eichler, emma, ruth, ziegellaub]" << std::endl;
}