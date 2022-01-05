set(BINARY longest_arithmetic_sequence_test)

add_executable(${BINARY} 1027.Longest-Arithmetic-Sequence.t.cpp)

target_link_libraries(${BINARY} gtest_main)

include(GoogleTest)

gtest_discover_tests(${BINARY})