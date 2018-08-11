#include "union_find.h"
#include <stdexcept>
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

// Boost requires actual/expected in its throw test?

BOOST_AUTO_TEST_CASE(union_find)
{
    UnionFind union_find(1);
}

BOOST_AUTO_TEST_CASE(union_find_can_not_be_empty)
{
    BOOST_REQUIRE_THROW(UnionFind(0), std::domain_error);
}

BOOST_AUTO_TEST_CASE(point_is_connected_to_itself)
{
    UnionFind union_find(1);
    BOOST_REQUIRE_EQUAL(union_find.is_connected(0, 0), true);
}

// BOOST_AUTO_TEST_CASE(empty_union_is_not_connected)
// {
    // UnionFind union_find(2);
    // BOOST_REQUIRE_EQUAL(union_find.is_connected(0, 1), false);
// }
