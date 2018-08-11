#include <boost/timer/timer.hpp>
#include <cmath>

void test_time()
{
    boost::timer::auto_cpu_timer t;
    // boost::timer::auto_cpu_timer t("%w seconds, wall time\n");
    // boost::timer::auto_cpu_timer t("%u seconds, user time\n");
    // boost::timer::auto_cpu_timer t("%s seconds, system time\n");

    for (long i = 0; i < 10000000; ++i)
        std::sqrt(123.456L); // burn some time

    // auto_cpu_timer automatically prints the time when it is destroyted
}

int main(void)
{
    test_time();
    test_time();
    return 0;
}
