#include "union_find.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(union_find)
{
    UnionFind uf(0);
}

BOOST_AUTO_TEST_CASE(empty_union_is_not_connected)
{
    UnionFind uf(0);
    BOOST_REQUIRE_EQUAL(false, uf.is_connected(0, 1));
}
