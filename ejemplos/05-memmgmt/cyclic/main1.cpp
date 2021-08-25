#include <memory>
#include <iostream>

struct nodo {
  std::shared_ptr<nodo> p;
};

void f() {
  auto a = std::make_shared<nodo>();
  auto b = std::make_shared<nodo>();
  a->p = b;
  b->p = a;
  //...
}

class cliente {
public:
  cliente() = default;
  explicit cliente(const std::string & c)
      : cuenta_{std::make_shared<std::string>(c)} {}
  std::shared_ptr<std::string> cuenta() { return cuenta_; }
  void quita_cuenta() { cuenta_ = nullptr; }

private:
  std::shared_ptr<std::string> cuenta_;
};

void g() {
  cliente juan{"01xyz"};
  auto c = juan.cuenta();
  std::cout << "c= [" << *c << "]\n";
  if (juan.cuenta()) {
    std::cout << "juan.cuenta()= [" << *juan.cuenta() << "]\n";
  }
  juan.quita_cuenta();
  std::cout << "c=" << *c << "\n";
  if (juan.cuenta()) {
    std::cout << "juan.cuenta()= [" << *juan.cuenta() << "]\n";
  }
}

int main() {
  f();
  g();
  return 0;
}
