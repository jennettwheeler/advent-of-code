cmake_minimum_required(VERSION 3.16.0)
project(aoc_2021 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_subdirectory(IProblem)
add_subdirectory(ProblemRunner)
add_subdirectory(Utility)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)
add_subdirectory(8)
add_subdirectory(9)
add_subdirectory(10)
add_subdirectory(11)
add_subdirectory(12)
add_subdirectory(13)
add_subdirectory(14)
add_subdirectory(15)
add_subdirectory(16)
add_subdirectory(17)
add_subdirectory(18)
add_subdirectory(19)
add_subdirectory(20)
add_subdirectory(21)
add_subdirectory(22)
add_subdirectory(23)
add_subdirectory(24)
add_subdirectory(25)

add_executable(${PROJECT_NAME} main.cpp register_problems.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE .)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ${PROJECT_NAME}_interface
    ${PROJECT_NAME}_runner
    ${PROJECT_NAME}_1)
