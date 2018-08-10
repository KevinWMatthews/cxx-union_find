#include "union_find.h"
#include <stdexcept>
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

// Boost requires actual/expected in its throw test?

BOOST_AUTO_TEST_CASE(union_find)
{
    UnionFind uf(1);
}

BOOST_AUTO_TEST_CASE(union_find_can_not_be_empty)
{
    BOOST_REQUIRE_THROW(UnionFind(0), std::domain_error);
}

BOOST_AUTO_TEST_CASE(empty_union_is_not_connected)
{
    UnionFind uf(1);
    BOOST_REQUIRE_EQUAL(uf.is_connected(0, 1), false);
}
