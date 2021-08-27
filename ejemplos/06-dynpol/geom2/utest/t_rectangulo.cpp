#include "rectangulo.hpp"

#include <gtest/gtest.h>

TEST(test_rectangulo, constr)// NOLINT
{
  using namespace geom;
  rectangulo r{punto{2.5, 1.5}, punto{3.0, 3.0}};
  EXPECT_EQ((punto{2.5, 1.5}), r.posicion());
  EXPECT_EQ(2.5, r.x());
  EXPECT_EQ(1.5, r.y());
  EXPECT_EQ(0.5, r.ancho());
  EXPECT_EQ(1.5, r.alto());
  EXPECT_EQ((punto{2.75,2.25}), r.centro());
}

TEST(test_rectangulo, move)// NOLINT
{
  using namespace geom;
  rectangulo r{punto{2.5, 2.5}, punto{3.0, 3.0}};
  r.desplaza(1.0, -1.0);
  EXPECT_EQ((punto{3.5, 1.5}), r.posicion());
}

TEST(test_rectangulo, area)// NOLINT
{
  using namespace geom;
  rectangulo r{punto{2.5, 2.5}, punto{3.0, 3.0}};
  EXPECT_EQ(0.25, r.area());
}

TEST(test_rectangulo, insercion_flujo)// NOLINT
{
  using namespace geom;
  rectangulo r{punto{2.5, 1.5}, punto{3.0, 3.0}};
  std::ostringstream os;
  os << r;
  EXPECT_STREQ("rectangulo: [figura: [2.5 , 1.5]] , 0.5 , 1.5 ]",
               os.str().c_str());
}