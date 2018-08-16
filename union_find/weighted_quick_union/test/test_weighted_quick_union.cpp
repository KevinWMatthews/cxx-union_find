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
