add_library(union_find
    union_find.cpp
)
target_include_directories(union_find
    PUBLIC "${CMAKE_HOME_DIRECTORY}/include"
)
set_property(TARGET union_find
    PROPERTY CXX_STANDARD 11
    PROPERTY CXX_STANDARD_REQUIRED ON
)
add_library(union_find::union_find ALIAS union_find)
