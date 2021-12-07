set(PROBLEM_NUM 9)
set(PROBLEM_NAME ${PROJECT_NAME}_${PROBLEM_NUM})

add_library(${PROBLEM_NAME} STATIC)
target_sources(${PROBLEM_NAME}
    PUBLIC
        Problem${PROBLEM_NUM}.h
    PRIVATE
        Problem${PROBLEM_NUM}.cpp)

target_link_libraries(${PROBLEM_NAME}
  PRIVATE
    ${PROJECT_NAME}_interface
    ${PROJECT_NAME}_utility)
target_include_directories(${PROBLEM_NAME} PUBLIC .)

add_executable(${PROBLEM_NAME}_test Test.cpp)
target_link_libraries(${PROBLEM_NAME}_test PRIVATE ${PROBLEM_NAME} ${PROJECT_NAME}_interface ${PROJECT_NAME}_runner)
add_test(${PROBLEM_NAME}_test ${PROBLEM_NAME}_test ${CMAKE_SOURCE_DIR}/${PROBLEM_NUM})