add_library(weighted_quick_union
    include/weighted_quick_union.h
    src/weighted_quick_union.cpp
)
target_include_directories(weighted_quick_union
    PUBLIC "${CMAKE_HOME_DIRECTORY}/include"
    PUBLIC include
)
set_property(TARGET weighted_quick_union
    PROPERTY CXX_STANDARD 11
    PROPERTY CXX_STANDARD_REQUIRED ON
)
add_library(weighted_quick_union::weighted_quick_union ALIAS weighted_quick_union)


add_subdirectory(test)
