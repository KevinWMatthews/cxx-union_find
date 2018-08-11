add_library(quick_find
    quick_find.cpp
)
target_include_directories(quick_find
    PUBLIC "${CMAKE_HOME_DIRECTORY}/include"
    PUBLIC "${CMAKE_HOME_DIRECTORY}/quick_find/include"
)
set_property(TARGET quick_find
    PROPERTY CXX_STANDARD 11
    PROPERTY CXX_STANDARD_REQUIRED ON
)
add_library(quick_find::quick_find ALIAS quick_find)
