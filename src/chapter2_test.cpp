#define BOOST_TEST_MODULE Chapter2 Tests
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "Color.h"
#include "Util.h"

BOOST_AUTO_TEST_CASE( constructor_test )
/* Create a new Tuple */
{
  Color c(-0.5, 0.4, 1.7);
  BOOST_TEST( equal(c.red(), -0.5));
  BOOST_TEST( equal(c.green(), 0.4));
  BOOST_TEST( equal(c.blue(), 1.7));
}
