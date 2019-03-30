cmake_minimum_required(VERSION 3.10)
project(sql-statement)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

# The verion number
set (TUTORIAL_VERSION_MAJOR 0)
set (TUTORIAL_VERSION_MINOR 1)

include_directories("${PROJECT_SOURCE_DIR}/include")
add_library(sql-statement "${PROJECT_SOURCE_DIR}/src/sql-statement.cpp")

install(TARGETS sql-statement DESTINATION "/usr/local/lib")
install(
	FILES "${PROJECT_SOURCE_DIR}/include/sql-statement.hpp"
	DESTINATION "/usr/local/include"
)
