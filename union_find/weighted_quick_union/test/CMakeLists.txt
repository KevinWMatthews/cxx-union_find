set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.62 REQUIRED
    COMPONENTS unit_test_framework
)

add_executable(test_weighted_quick_union
    test_weighted_quick_union.cpp
)
target_link_libraries(test_weighted_quick_union
    weighted_quick_union::weighted_quick_union
    Boost::unit_test_framework
)
set_property(TARGET test_weighted_quick_union
    PROPERTY CXX_STANDARD 11
    PROPERTY CXX_STANDARD_REQUIRED ON
)
add_test(
    NAME test_weighted_quick_union
    COMMAND test_weighted_quick_union
)
