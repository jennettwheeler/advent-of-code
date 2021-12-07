add_library(aoc_2021_1 STATIC)
target_sources(aoc_2021_1
    PUBLIC
        Problem1.h
    PRIVATE
        Problem1.cpp)
target_link_libraries(aoc_2021_1 PRIVATE aoc_2021_interface)
target_include_directories(aoc_2021_1 PUBLIC .)