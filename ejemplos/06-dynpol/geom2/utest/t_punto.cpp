#include <gtest/gtest.h>

#include "punto.hpp"

TEST(test_punto, comparacion_igual) // NOLINT
{
  using namespace geom;
  punto p{1.0, 2.0};
  punto q{1.0, 2.0};
  punto r{1.0,3.0};
  EXPECT_TRUE(p==q);
  EXPECT_TRUE(p!=r);
}

TEST(test_punto, suma) // NOLINT
{
  using namespace geom;
  punto p{1.5, 2.5};
  desplazamiento d{1.0,1.0};
  EXPECT_EQ((punto{2.5,3.5}), p+d);
}

TEST(test_punto, suma_igual) // NOLINT
{
  using namespace geom;
  punto p{1.5, 2.5};
  desplazamiento d{1.0,1.0};
  p += d;
  EXPECT_EQ((punto{2.5,3.5}), p);
}

TEST(test_punto, insercion_flujo) // NOLINT
{
  using namespace geom;
  punto p{1.5, 3.5};
  std::ostringstream os;
  os << p;
  EXPECT_STREQ("[1.5 , 3.5]", os.str().c_str());
}