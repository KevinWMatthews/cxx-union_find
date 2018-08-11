add_library(quick_union
    include/quick_union.h
    src/quick_union.cpp
)
target_include_directories(quick_union
    PUBLIC "${CMAKE_HOME_DIRECTORY}/include"
    PUBLIC include
)
set_property(TARGET quick_union
    PROPERTY CXX_STANDARD 11
    PROPERTY CXX_STANDARD_REQUIRED ON
)
add_library(quick_union::quick_union ALIAS quick_union)
