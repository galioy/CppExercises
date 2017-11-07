cmake_minimum_required(VERSION 3.8)
project(exercises)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(exercises ${SOURCE_FILES})

add_executable(ex0101 ex0101)
add_executable(ex0102 ex0102)
add_executable(ex0103 ex0103)
add_executable(ex0104 ex0104)

add_executable(ex0201 ex0201)
add_executable(ex0202 ex0202)
add_executable(ex0203 ex0203)
add_executable(ex0204 ex0204)

add_executable(ex0301 ex0301)
add_executable(ex0302 ex0302)

add_executable(ex0401 ex0401)
add_executable(ex0402 ex0402)
add_executable(ex0403 ex0403)

add_executable(ex0501 ex0501)
add_executable(ex0502 ex0502)
add_executable(ex0503 ex0503)

add_executable(ex0601 ex0601)

add_executable(ex0701 ex0701)

add_executable(shapes-main shapes-main)

add_executable(ex0901 ex0901)
add_executable(ex0902 ex0902)
add_executable(ex0903 ex0903)
add_executable(ex0904 ex0904)

add_executable(doubly-linked-main doubly-linked-main)

add_executable(fibonacci-tree fibonacci-tree)
