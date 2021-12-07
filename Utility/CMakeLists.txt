add_library(${PROJECT_NAME}_utility STATIC)
target_sources(${PROJECT_NAME}_utility
  PUBLIC
    include/Utility.h
  PRIVATE
    src/Utility.cpp)

target_include_directories(${PROJECT_NAME}_utility PUBLIC include)