project(cmocka C)

# Required cmake version
cmake_minimum_required(VERSION 3.10.2)

#set CMOCKA_INCLUDE
set(CMOCKA_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/libs/include)
set(CMOCKA_lib ${CMAKE_CURRENT_SOURCE_DIR}/libs/cmocka/libcmocka.so)

add_subdirectory(test_cmocka_demo)

