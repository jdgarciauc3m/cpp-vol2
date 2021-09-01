#ifndef GEOM2_FIGURA_HPP
#define GEOM2_FIGURA_HPP

#include "punto.hpp"

#include <iosfwd>
#include <mincontracts/mincontracts.hpp>
#include <memory>

namespace geom {

  class figura {
  public:
    explicit figura(punto p) noexcept : posicion_{p} {}
  protected:
    figura(const figura &) noexcept = default;
    figura & operator=(const figura &) noexcept = default;
    figura(figura &&) noexcept = default;
    figura & operator=(figura &&) noexcept = default;
  public:
    virtual ~figura() = default;

    [[nodiscard]] std::unique_ptr<figura> clona() const {
      return std::unique_ptr<figura>{clona_impl()};
    }

    [[nodiscard]] virtual punto centro() const noexcept { return posicion_; }

    [[nodiscard]] virtual double area() const noexcept = 0;

    void desplaza(desplazamiento d) noexcept { posicion_ += d; }
    virtual void refleja_x() noexcept = 0;

    virtual void inserta(std::ostream & os) const;

  private:
    [[nodiscard]] virtual figura * clona_impl() const = 0;

  protected:
    punto posicion_;
  };

  std::ostream & operator<<(std::ostream & os, const figura & f);

}// namespace geom

#endif// GEOM2_FIGURA_HPP