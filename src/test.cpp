#define BOOST_TEST_MODULE Tuple test
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "Tuple.h"


BOOST_AUTO_TEST_CASE( constructor_test )
/* Create a new Tuple */
{
  Tuple t1(1.0, 2.0, 3.0, 1.0);
  BOOST_TEST( t1.x() == 1.0 );
}
