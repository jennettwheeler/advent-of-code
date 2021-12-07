add_library(aoc_2021_2 STATIC)
target_sources(aoc_2021_2
    PUBLIC
        Problem2.h
    PRIVATE
        Problem2.cpp)
target_link_libraries(aoc_2021_2 PRIVATE aoc_2021_interface)
target_include_directories(aoc_2021_2 PUBLIC .)