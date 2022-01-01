set(BINARY escape_a_large_maze_1036_test)

add_executable(${BINARY} 1036.Escape-a-Large-Maze.t.cpp)

target_link_libraries(${BINARY} gtest_main)

include(GoogleTest)

gtest_discover_tests(${BINARY})