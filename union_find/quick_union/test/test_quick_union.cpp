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

BOOST_AUTO_TEST_CASE(can_connect_points)
{
    QuickUnion quick_union(2);
    BOOST_REQUIRE_EQUAL(quick_union.connect(0, 1), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 1), true);
}

BOOST_AUTO_TEST_CASE(several_points_are_disconnected_by_default)
{
    QuickUnion quick_union(3);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 1), false);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 2), false);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 2), false);
}

BOOST_AUTO_TEST_CASE(connecting_some_does_not_connect_all)
{
    QuickUnion quick_union(3);
    quick_union.connect(1, 2);

    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 1), false);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 2), false);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 2), true);
}

BOOST_AUTO_TEST_CASE(connect_is_transitive)
{
    QuickUnion quick_union(3);
    quick_union.connect(0, 1);
    quick_union.connect(1, 2);

    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 2), true);
}

BOOST_AUTO_TEST_CASE(distinct_components_are_not_connected)
{
    QuickUnion quick_union(4);

    // Create two "component" (set of connected elements):
    // { 0 1 } { 2 3 }
    quick_union.connect(0, 1);
    quick_union.connect(2, 3);

    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 2), false);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 2), false);

    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 3), false);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 3), false);
}

BOOST_AUTO_TEST_CASE(connect_series_of_elements)
{
    QuickUnion quick_union(4);

    quick_union.connect(0, 1);
    quick_union.connect(1, 2);
    quick_union.connect(2, 3);

    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 1), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 2), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 3), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 2), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 3), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(2, 3), true);
}

BOOST_AUTO_TEST_CASE(connecting_inner_components_connects_all_elements)
{
    // { 0 1 } { 2 3 }  => { 0 1 2 3 }
    // after 1 and 2 are connected
    QuickUnion quick_union(4);

    quick_union.connect(0, 1);
    quick_union.connect(2, 3);
    quick_union.connect(1, 2);

    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 1), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 2), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 3), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 2), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 3), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(2, 3), true);
}

BOOST_AUTO_TEST_CASE(connecting_outer_elements_of_components_connects_elements)
{
    // { 0 1 } { 2 3 }  => { 0 1 2 3 }
    // after 0 and 3 are connected
    QuickUnion quick_union(4);

    quick_union.connect(0, 1);
    quick_union.connect(2, 3);
    quick_union.connect(0, 3);

    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 1), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 2), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 3), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 2), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 3), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(2, 3), true);
}

BOOST_AUTO_TEST_CASE(connecting_first_elements_of_components_connects_elements)
{
    // { 0 1 } { 2 3 }  => { 0 1 2 3 }
    // after 0 and 2 are connected
    QuickUnion quick_union(4);

    quick_union.connect(0, 1);
    quick_union.connect(2, 3);
    quick_union.connect(0, 2);

    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 1), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 2), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 3), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 2), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 3), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(2, 3), true);
}

BOOST_AUTO_TEST_CASE(connecting_last_elements_of_components_connects_elements)
{
    // { 0 1 } { 2 3 }  => { 0 1 2 3 }
    // after 0 and 2 are connected
    QuickUnion quick_union(4);

    quick_union.connect(0, 1);
    quick_union.connect(2, 3);
    quick_union.connect(1, 2);

    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 1), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 2), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 3), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 2), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 3), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(2, 3), true);
}

BOOST_AUTO_TEST_CASE(single_element_can_have_multiple_connections)
{
    // { 0 1 2 }
    QuickUnion quick_union(3);

    quick_union.connect(0, 1);
    quick_union.connect(0, 2);

    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 1), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(0, 2), true);
    BOOST_REQUIRE_EQUAL(quick_union.is_connected(1, 2), true);
}
