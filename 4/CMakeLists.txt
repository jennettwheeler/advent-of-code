add_library(aoc_2021_4 STATIC)
target_sources(aoc_2021_4
    PUBLIC
        Problem4.h
    PRIVATE
        Problem4.cpp)
target_link_libraries(aoc_2021_4 PRIVATE aoc_2021_interface)
target_include_directories(aoc_2021_4 PUBLIC .)