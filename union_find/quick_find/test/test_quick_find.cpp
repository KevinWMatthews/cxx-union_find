#include "quick_find.h"
#include <stdexcept>
#include <string>
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>

namespace
{

// BOOST_<level>_EXCEPTION() accepts a predicate (function returning a boolean) as its third argument.
// Use this to check if the exception throws the desired message.
// Boost has full control over the argument to the predicate, so
// generate a lambda and capture the expectation.
auto require_exception_message(std::string expected)
{
    return [expected](const std::logic_error& except)
    {
        BOOST_REQUIRE(boost::algorithm::contains(except.what(), expected));
        return true;
    };
}

}


BOOST_AUTO_TEST_CASE(can_be_created)
{
    QuickFind quick_find(1);
}

BOOST_AUTO_TEST_CASE(can_not_be_empty)
{
    auto is_correct_message = require_exception_message("QuickFind::QuickFind");
    BOOST_REQUIRE_EXCEPTION(QuickFind(0), std::domain_error, is_correct_message);
}

BOOST_AUTO_TEST_CASE(point_is_connected_to_itself)
{
    QuickFind quick_find(1);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 0), true);
}

BOOST_AUTO_TEST_CASE(points_are_not_connected_by_default)
{
    QuickFind quick_find(2);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 1), false);
}

BOOST_AUTO_TEST_CASE(do_not_check_connection_if_point_is_out_of_range)
{
    QuickFind quick_find(2);
    auto is_correct_message = require_exception_message("QuickFind::is_connected");

    BOOST_REQUIRE_EXCEPTION(quick_find.is_connected(0, 2), std::out_of_range, is_correct_message);
    BOOST_REQUIRE_EXCEPTION(quick_find.is_connected(2, 0), std::out_of_range, is_correct_message);
}

BOOST_AUTO_TEST_CASE(can_connect_points)
{
    QuickFind quick_find(2);
    BOOST_REQUIRE_EQUAL(quick_find.connect(0, 1), true);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 1), true);
}

BOOST_AUTO_TEST_CASE(do_not_connect_points_out_of_range)
{
    QuickFind quick_find(1);
    auto is_correct_message = require_exception_message("QuickFind::connect");

    BOOST_REQUIRE_EXCEPTION(quick_find.connect(0, 1), std::out_of_range, is_correct_message);
    BOOST_REQUIRE_EXCEPTION(quick_find.connect(1, 0), std::out_of_range, is_correct_message);
}

BOOST_AUTO_TEST_CASE(several_points_are_disconnected_by_default)
{
    QuickFind quick_find(3);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 1), false);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 2), false);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(1, 2), false);
}

BOOST_AUTO_TEST_CASE(connecting_some_does_not_connect_all)
{
    QuickFind quick_find(3);
    quick_find.connect(1, 2);

    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 1), false);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 2), false);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(1, 2), true);
}

BOOST_AUTO_TEST_CASE(connect_is_transitive)
{
    QuickFind quick_find(3);
    quick_find.connect(0, 1);
    quick_find.connect(1, 2);

    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 2), true);
}

BOOST_AUTO_TEST_CASE(distinct_components_are_not_connected)
{
    QuickFind quick_find(4);

    // Create two "component" (set of connected elements):
    // { 0 1 } { 2 3 }
    quick_find.connect(0, 1);
    quick_find.connect(2, 3);

    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 2), false);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(1, 2), false);

    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 3), false);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(1, 3), false);
}

BOOST_AUTO_TEST_CASE(connect_series_of_elements)
{
    QuickFind quick_find(4);

    quick_find.connect(0, 1);
    quick_find.connect(1, 2);
    quick_find.connect(2, 3);

    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 1), true);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 2), true);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 3), true);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(1, 2), true);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(1, 3), true);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(2, 3), true);
}

BOOST_AUTO_TEST_CASE(connecting_components_connects_all_elements)
{
    // { 0 1 } { 2 3 }  => { 0 1 2 3 }
    // after 1 and 2 are connected
    QuickFind quick_find(4);

    quick_find.connect(0, 1);
    quick_find.connect(2, 3);
    quick_find.connect(1, 2);

    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 2), true);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(1, 2), true);

    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 3), true);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(1, 3), true);
}

BOOST_AUTO_TEST_CASE(connecting_components_is_commutative)
{
    // { 0 1 } { 2 3 }  => { 0 1 2 3 }
    // after 0 and 3 are connected
    QuickFind quick_find(4);

    quick_find.connect(0, 1);
    quick_find.connect(2, 3);
    quick_find.connect(0, 3);

    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 2), true);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(1, 2), true);

    BOOST_REQUIRE_EQUAL(quick_find.is_connected(0, 3), true);
    BOOST_REQUIRE_EQUAL(quick_find.is_connected(1, 3), true);
}
