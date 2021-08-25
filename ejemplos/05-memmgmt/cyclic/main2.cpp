#include <memory>
#include <iostream>

struct nodo {
  std::weak_ptr<nodo> p;
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
  std::weak_ptr<std::string> cuenta() { return cuenta_; }
  void quita_cuenta() { cuenta_ = nullptr; }

private:
  std::shared_ptr<std::string> cuenta_;
};

void imprime(const std::string& str, const std::weak_ptr<std::string>& w) {
  std::cout << str << " = [";
  if (!w.expired()) {
    std::cout << *w.lock();
  }
  std::cout << "]\n";
}

void g() {
  cliente juan{"01xyz"};
  auto c = juan.cuenta();
  imprime("c",c);
  imprime("juan.cuenta()", juan.cuenta());
  juan.quita_cuenta();
  imprime("c",c);
  imprime("juan.cuenta()", juan.cuenta());
}
int main() {
  f();
  g();
  return 0;
}
