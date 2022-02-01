set(BINARY count_of_smaller_numbers_after_self)

# divided conquer solution
add_library(divided_conquer_315 SHARED 315.divided-conquer.cpp)
target_include_directories(divided_conquer_315 PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR})

# binary indexed tree solution
add_library(binary_indexed_tree_315 SHARED 315.binary-indexed-tree.cpp)
target_include_directories(binary_indexed_tree_315 PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR})

# configure file for compilation
set(BIT_315_SO  ${CMAKE_CURRENT_BINARY_DIR}/libbinary_indexed_tree_315.so)
set(DC_315_SO   ${CMAKE_CURRENT_BINARY_DIR}/libdivided_conquer_315.so)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/315.Count-of-Smaller-Numbers-After-Self.t.cpp.in
  ${CMAKE_CURRENT_BINARY_DIR}/315.Count-of-Smaller-Numbers-After-Self.t.cpp)

set(SRC_FILE
    ${CMAKE_CURRENT_BINARY_DIR}/315.Count-of-Smaller-Numbers-After-Self.t.cpp)

# main test
add_executable(${BINARY} ${SRC_FILE})

target_link_libraries(${BINARY} gtest_main dl)
target_include_directories(${BINARY} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include(GoogleTest)

gtest_discover_tests(${BINARY})