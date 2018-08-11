set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.62 REQUIRED
    COMPONENTS unit_test_framework
)

add_executable(test_quick_union
    test_quick_union.cpp
)
target_link_libraries(test_quick_union
    PRIVATE
        quick_union::quick_union
        Boost::unit_test_framework
)
set_property(TARGET test_quick_find
    PROPERTY CXX_STANDARD 11
    PROPERTY CXX_STANDARD_REQUIRED ON
)
add_test(
    NAME test_quick_union
    COMMAND test_quick_union
)
