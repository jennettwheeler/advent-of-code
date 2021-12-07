add_library(aoc_2021_interface INTERFACE)
target_sources(aoc_2021_interface
INTERFACE
    include/IProblem.h)

target_include_directories(aoc_2021_interface INTERFACE include)
