#include <iostream>
#include "array.hpp"

int main() {
  cont::array<int,16> vec1{};
  cont::array<double,8> vec2{1.0, 2.0, 3.0};

  for (int i=0; i< vec1.tamanyo(); ++i) {
    std::cout << vec1[i] << ' ';
  }
  std::cout << "\n";

  for (int i=0; i< vec2.tamanyo(); ++i) {
    std::cout << vec2[i] << ' ';
  }
  std::cout << "\n";



  return 0;
}
