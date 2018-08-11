#include "quick_union.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(can_be_created)
{
    QuickUnion quick_union(1);
}

BOOST_AUTO_TEST_CASE(can_not_be_empty)
{
    BOOST_REQUIRE_THROW(QuickUnion(0), std::domain_error);
}

BOOST_AUTO_TEST_CASE(point_is_connected_to_itself)
{
    QuickUnion quick_union(1);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 0), true);
}

BOOST_AUTO_TEST_CASE(points_are_not_connected_by_default)
{
    QuickUnion quick_union(2);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 1), false);
}

// BOOST_AUTO_TEST_CASE(can_connect_points)
// {
    // QuickUnion quick_union(2);
    // BOOST_REQUIRE_EQUAL(quick_union.connect(0, 1), true);
    // BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 1), true);
// }
