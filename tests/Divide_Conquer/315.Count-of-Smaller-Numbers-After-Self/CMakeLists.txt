set(BINARY count_of_smaller_numbers_after_self)

add_executable(${BINARY} 315.Count-of-Smaller-Numbers-After-Self.t.cpp)

target_link_libraries(${BINARY} gtest_main)

include(GoogleTest)

gtest_discover_tests(${BINARY})