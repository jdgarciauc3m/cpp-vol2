#include "listnum.hpp"

listnum::listnum() : inicio_{std::make_shared<node>(0)}, fin_{inicio_} {}

listnum::listnum(int n) : listnum() {
  for (int i = 0; i < n; ++i) { agrega_final(0.0); }
}

listnum::listnum(std::initializer_list<double> l) : listnum() {
  for (auto x : l) { agrega_final(x); }
}

listnum::listnum(const listnum & l) : listnum() {
  std::shared_ptr<listnum::node> aux = l.inicio_;
  while (aux != l.fin_) {
    agrega_final(aux->valor_);
    aux = aux->sig_;
  }
}

listnum & listnum::operator=(const listnum & l) {
  if (this == &l) { return *this; }
  std::shared_ptr<listnum::node> aux = l.inicio_;
  while (aux != l.fin_) {
    agrega_final(aux->valor_);
    aux = aux->sig_;
  }
  return *this;
}

void listnum::agrega_final(double x) {
  auto aux = std::make_shared<node>(x);
  aux->ant_ = fin_->ant_;
  aux->sig_ = fin_;
  if (inicio_ == fin_) {
    inicio_ = aux;
  } else {
    fin_->ant_.lock()->sig_ = aux;
  }
  fin_->ant_ = aux;
}

int listnum::tamanyo() const noexcept {
  std::weak_ptr<listnum::node> aux = inicio_;
  int n = 0;
  while (aux.lock() != fin_) {
    n++;
    aux = aux.lock()->sig_;
  }
  return n;
}

std::ostream & operator<<(std::ostream & os, const listnum & l) {
  auto it = l.inicio();
  os << *it;
  ++it;
  for (; it!=l.fin(); ++it) {
    os << ", " << *it;
  }
  return os;
}

