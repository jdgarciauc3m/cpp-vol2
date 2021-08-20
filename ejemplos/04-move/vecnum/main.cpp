#include <iostream>

#include "vecnum.hpp"

vecnum make() {
  return {1,2,3};
  /*
  vecnum r{9,8,7};
  r[2]=99;
  return r;*/
}

int main() {
  std::cout << "Init v\n";
  vecnum v{1,2,3};
  std::cout << "Init w\n";
  vecnum w(5);
  std::cout << "Init t\n";
  vecnum t = make();
  std::cout << "w=make()\n";
  w = make();
  std::cout << "v = move(t)\n";
  v = std::move(t);
  std::cout << "v= (" << v << ")\n";
  std::cout << "w= (" << w << ")\n";
  std::cout << "t= (" << t << ")\n";
  return 0;
}
