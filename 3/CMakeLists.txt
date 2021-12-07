add_library(aoc_2021_3 STATIC)
target_sources(aoc_2021_3
    PUBLIC
        Problem3.h
    PRIVATE
        Problem3.cpp)
target_link_libraries(aoc_2021_3 PRIVATE aoc_2021_interface)
target_include_directories(aoc_2021_3 PUBLIC .)