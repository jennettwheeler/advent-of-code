add_library(aoc_2021_runner STATIC)
target_sources(aoc_2021_runner
  PUBLIC
    include/ProblemRunner.h
  PRIVATE
    src/ProblemRunner.cpp)

target_include_directories(aoc_2021_runner PUBLIC include)
target_link_libraries(aoc_2021_runner
  PRIVATE
  aoc_2021_interface)
