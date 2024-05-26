# Required cmake version
cmake_minimum_required(VERSION 3.10.2)

set(all_include ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB all_src ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

add_executable(test_cmocka ${all_src})

target_include_directories(test_cmocka PUBLIC ${CMOCKA_INCLUDE}
                                              ${all_include})

target_link_libraries(test_cmocka PUBLIC ${CMOCKA_lib})
