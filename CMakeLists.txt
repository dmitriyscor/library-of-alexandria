cmake_minimum_required(VERSION 3.10)
project(library-of-alexandria)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(unofficial-sqlite3 CONFIG REQUIRED)


add_executable(main_exe backend/main.cpp)

target_link_libraries(main_exe PRIVATE unofficial::sqlite3::sqlite3)   