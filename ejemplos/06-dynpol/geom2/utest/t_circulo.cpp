#include "circulo.hpp"

#include <gtest/gtest.h>

TEST(test_circulo, constr) // NOLINT
{
  using namespace geom;
  circulo c{punto{2.5, 1.5}, 3.0};
  EXPECT_EQ((punto{2.5,1.5}), c.centro());
  EXPECT_EQ(3.0, c.radio());
}

TEST(test_circulo, clonacion) // NOLINT
{
  using namespace geom;
  circulo c{punto{1.0,1.0}, 3.0};
  figura & f = c;
  auto d = f.clona();
  EXPECT_EQ((punto{1.0,1.0}), d->centro());
}

TEST(test_circulo, desplaza) // NOLINT
{
  using namespace geom;
  circulo c{punto{2.5, 2.5}, 3.0};
  c.desplaza(desplazamiento{1.0, -1.0});
  EXPECT_EQ((punto{3.5,1.5}), c.centro());
}

TEST(test_circulo, desplaza_diagonal) // NOLINT
{
  using namespace geom;
  circulo c{punto{2.5, 2.5}, 3.0};
  c.desplaza(1.0);
  EXPECT_EQ((punto{3.5,3.5}), c.centro());
}

TEST(test_circulo, area) // NOLINT
{
  using namespace geom;
  circulo c{punto{2.5, 2.5}, 3.0};
  EXPECT_LT(9 * 3.14, c.area());
  EXPECT_GT(9 * 3.15, c.area());
}

TEST(test_circulo, insercion_flujo) // NOLINT
{
  using namespace geom;
  circulo c{punto{2.5, 1.5}, 3.5};
  std::ostringstream os;
  os << c;
  EXPECT_STREQ("circulo: [figura: [2.5 , 1.5] , 3.5]", os.str().c_str());
}