cmake_minimum_required(VERSION 3.0)

enable_testing()

set(CMAKE_C_FLAGS "-mcrc32 -march=core-avx2")
set(CMAKE_C_FLAGS_RELEASE "-O3")

add_executable(test1_32 test1_32.c)
add_executable(test2_16 test2_16.c)
add_executable(test3_8  test3_8.c)
add_executable(test4_b  test4_b.c)

add_test(NAME test3_8  COMMAND test3_8 )
add_test(NAME test2_16 COMMAND test2_16)
add_test(NAME test1_32 COMMAND test1_32)
add_test(NAME test4_b  COMMAND test4_b)
