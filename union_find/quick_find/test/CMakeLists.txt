# See https://cmake.org/cmake/help/v3.5/module/FindBoost.html for details
# Copied these settings from exercism... not sure about the configuration yet.
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.62 REQUIRED
    COMPONENTS unit_test_framework timer chrono
)

add_executable(test_quick_find
    test_quick_find.cpp
)
target_include_directories(test_quick_find
    PRIVATE ${Boost_INCLUDE_DIRS}
)
target_link_libraries(test_quick_find
    quick_find::quick_find
    Boost::unit_test_framework
)
set_property(TARGET test_quick_find
    PROPERTY CXX_STANDARD 11
    PROPERTY CXX_STANDARD_REQUIRED ON
)
add_test(
    NAME test_quick_find
    COMMAND test_quick_find
)

add_executable(benchmark_quick_find
    benchmark_quick_find.cpp
)
target_include_directories(benchmark_quick_find
    PRIVATE ${Boost_INCLUDE_DIRS}
)
target_link_libraries(benchmark_quick_find
    quick_find::quick_find
    Boost::unit_test_framework
    Boost::timer
    Boost::chrono
)
