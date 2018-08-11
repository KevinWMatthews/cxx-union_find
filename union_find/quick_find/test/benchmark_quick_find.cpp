#include "quick_find.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/timer/timer.hpp>
#include <cmath>

// auto_cpu_timer automatically prints the time when it is destroyted
// Format the output time using:
//      %w      wall time
//      %u      user time
//      %s      system time

BOOST_AUTO_TEST_CASE(fastest_possible_time)
{
    boost::timer::auto_cpu_timer t;

    QuickFind quick_find(1);
    quick_find.is_connected(0, 0);
}

BOOST_AUTO_TEST_CASE(initialize_two_elements)
{
    boost::timer::auto_cpu_timer t;

    QuickFind quick_find(2);
    quick_find.is_connected(0, 1);
}

BOOST_AUTO_TEST_CASE(initialize_one_thousand_elements)
{
    boost::timer::auto_cpu_timer t;

    QuickFind quick_find(1000);
    quick_find.is_connected(0, 1);
}

BOOST_AUTO_TEST_CASE(initialize_one_million_elements)
{
    boost::timer::auto_cpu_timer t;

    QuickFind quick_find(1'000'000);
    quick_find.is_connected(0, 1);
}
