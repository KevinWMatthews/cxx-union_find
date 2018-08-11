#include "union_find.h"
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

    UnionFind union_find(1);
    union_find.is_connected(0, 0);
}

