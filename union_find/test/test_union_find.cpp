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

BOOST_AUTO_TEST_CASE(points_are_not_connected_by_default)
{
    UnionFind union_find(2);
    BOOST_REQUIRE_EQUAL(union_find.is_connected(0, 1), false);
}

BOOST_AUTO_TEST_CASE(can_connect_points)
{
    UnionFind union_find(2);
    BOOST_REQUIRE_EQUAL(union_find.connect(0, 1), true);
    BOOST_REQUIRE_EQUAL(union_find.is_connected(0, 1), true);
}

BOOST_AUTO_TEST_CASE(several_points_are_disconnected_by_default)
{
    UnionFind union_find(3);
    BOOST_REQUIRE_EQUAL(union_find.is_connected(0, 1), false);
    BOOST_REQUIRE_EQUAL(union_find.is_connected(0, 2), false);
    BOOST_REQUIRE_EQUAL(union_find.is_connected(1, 2), false);
}

BOOST_AUTO_TEST_CASE(connecting_some_does_not_connect_all)
{
    UnionFind union_find(3);
    union_find.connect(1, 2);

    BOOST_REQUIRE_EQUAL(union_find.is_connected(0, 1), false);
    BOOST_REQUIRE_EQUAL(union_find.is_connected(0, 2), false);
    BOOST_REQUIRE_EQUAL(union_find.is_connected(1, 2), true);
}

BOOST_AUTO_TEST_CASE(connect_is_transitive)
{
    UnionFind union_find(3);
    union_find.connect(0, 1);
    union_find.connect(1, 2);

    BOOST_REQUIRE_EQUAL(union_find.is_connected(0, 2), true);
}

BOOST_AUTO_TEST_CASE(distinct_components_are_not_connected)
{
    UnionFind union_find(4);

    // Create two "component" (set of connected elements):
    // { 0 1 } { 2 3 }
    union_find.connect(0, 1);
    union_find.connect(2, 3);

    BOOST_REQUIRE_EQUAL(union_find.is_connected(0, 2), false);
    BOOST_REQUIRE_EQUAL(union_find.is_connected(1, 2), false);

    BOOST_REQUIRE_EQUAL(union_find.is_connected(0, 3), false);
    BOOST_REQUIRE_EQUAL(union_find.is_connected(1, 3), false);
}
