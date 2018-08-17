#include "weighted_quick_union.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(can_be_created)
{
    WeightedQuickUnion weighted_quick_union(1);
}

BOOST_AUTO_TEST_CASE(can_not_be_empty)
{
    BOOST_REQUIRE_THROW(WeightedQuickUnion(0), std::domain_error);
}

BOOST_AUTO_TEST_CASE(point_is_connected_to_itself)
{
    WeightedQuickUnion weighted_quick_union(1);
    BOOST_REQUIRE_EQUAL(weighted_quick_union.is_connected(0, 0), true);
    BOOST_REQUIRE_EQUAL(weighted_quick_union.max_depth(), 0);
}

BOOST_AUTO_TEST_CASE(points_are_not_connected_by_default)
{
    WeightedQuickUnion weighted_quick_union(2);
    BOOST_REQUIRE_EQUAL(weighted_quick_union.is_connected(0, 1), false);
    BOOST_REQUIRE_EQUAL(weighted_quick_union.is_connected(1, 0), false);
}

BOOST_AUTO_TEST_CASE(do_not_check_connection_if_point_is_out_of_range)
{
    WeightedQuickUnion weighted_quick_union(2);

    BOOST_REQUIRE_THROW(weighted_quick_union.is_connected(0, 2), std::out_of_range);
    BOOST_REQUIRE_THROW(weighted_quick_union.is_connected(2, 0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(can_connect_points)
{
    WeightedQuickUnion weighted_quick_union(2);
    BOOST_REQUIRE_EQUAL(weighted_quick_union.connect(0, 1), true);
    BOOST_REQUIRE_EQUAL(weighted_quick_union.is_connected(0, 1), true);
    BOOST_REQUIRE_EQUAL(weighted_quick_union.max_depth(), 1);
}

BOOST_AUTO_TEST_CASE(two_points_can_be_connected_in_either_order)
{
    WeightedQuickUnion weighted_quick_union(2);
    weighted_quick_union.connect(1, 0);
    BOOST_REQUIRE_EQUAL(weighted_quick_union.is_connected(0, 1), true);
    BOOST_REQUIRE_EQUAL(weighted_quick_union.is_connected(1, 0), true);
}

BOOST_AUTO_TEST_CASE(do_not_connect_points_out_of_range)
{
    WeightedQuickUnion weighted_quick_union(1);

    BOOST_REQUIRE_THROW(weighted_quick_union.connect(0, 1), std::out_of_range);
    BOOST_REQUIRE_THROW(weighted_quick_union.connect(1, 0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(several_points_are_disconnected_by_default)
{
    WeightedQuickUnion weighted_quick_union(3);
    BOOST_REQUIRE_EQUAL(weighted_quick_union.is_connected(0, 1), false);
    BOOST_REQUIRE_EQUAL(weighted_quick_union.is_connected(0, 2), false);
    BOOST_REQUIRE_EQUAL(weighted_quick_union.is_connected(1, 2), false);
}
