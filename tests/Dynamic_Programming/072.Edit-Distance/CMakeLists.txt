set(BINARY edit_distance_test)

add_executable(${BINARY} 072.Edit-Distance.t.cpp)

target_link_libraries(${BINARY} gtest_main)

include(GoogleTest)

gtest_discover_tests(${BINARY})