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
}