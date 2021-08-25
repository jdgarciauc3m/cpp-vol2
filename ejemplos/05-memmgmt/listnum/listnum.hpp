#ifndef LISTNUM_LISTNUM_HPP
#define LISTNUM_LISTNUM_HPP

#include <memory>

class listnum {
public:
  listnum();
  explicit listnum(int n);
  listnum(std::initializer_list<double> l);

  listnum(const listnum & l);
  listnum & operator=(const listnum & l);

  listnum(listnum &&) = default;
  listnum & operator=(listnum &&) = default;

  ~listnum() = default;

  [[nodiscard]] int tamanyo() const noexcept;

  void agrega_final(double x);

private:
  struct node {
    explicit node(double x) : valor_{x} {}
    double valor_;
    std::shared_ptr<node> sig_;
    std::weak_ptr<node> ant_;
  };

  std::shared_ptr<node> inicio_;
  std::shared_ptr<node> fin_;

public:
  class iterador {
  public:
    explicit iterador(const std::shared_ptr<node> & p) : actual_{p} {}
    double & operator*() { return actual_.lock()->valor_; }
    iterador operator++() {
      actual_ = actual_.lock()->sig_;
      return *this;
    }
    bool operator==(const iterador & it) const {
      return actual_.lock() == it.actual_.lock();
    }
    bool operator!=(const iterador & it) const {
      return actual_.lock() != it.actual_.lock();
    }

  private:
    std::weak_ptr<node> actual_;
  };

  [[nodiscard]] iterador inicio() const { return iterador{inicio_}; }
  [[nodiscard]] iterador fin() const { return iterador{fin_}; }
};

std::ostream & operator<<(std::ostream & os, const listnum & list);


#endif// LISTNUM_LISTNUM_HPP
