#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/timer/timer.hpp>
#include <cmath>

BOOST_AUTO_TEST_CASE(local_performance_test)
{
    boost::timer::auto_cpu_timer t;
    // boost::timer::auto_cpu_timer t("%w seconds, wall time\n");
    // boost::timer::auto_cpu_timer t("%u seconds, user time\n");
    // boost::timer::auto_cpu_timer t("%s seconds, system time\n");

    for (long i = 0; i < 10000000; ++i)
        std::sqrt(123.456L); // burn some time

    // auto_cpu_timer automatically prints the time when it is destroyted
}
