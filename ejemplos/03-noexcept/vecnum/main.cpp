#include <iostream>

#include "vecnum.hpp"

int main() {
  vecnum v(5); // NOLINT(cppcoreguidelines-avoid-magic-numbers)
  vecnum w{1,2,3};
  v = w;
  return 0;
}
