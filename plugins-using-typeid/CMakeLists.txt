cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_COMPILER clang++)

project(plugins_test)

include(GenerateExportHeader)

find_package(Qt5Core REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)

# Not using libc++ fixes the problem. Comment that line
set(CMAKE_CXX_FLAGS "-stdlib=libc++")

add_library(mydependency SHARED mydependency.cpp)
generate_export_header(mydependency)

add_definitions(-DTYPE_TO_REGISTER=QObject)

add_executable(main main.cpp)
target_link_libraries(main Qt5::Core mydependency)
target_compile_definitions(main PRIVATE -DBUILD_DIR="${CMAKE_BINARY_DIR}")

add_library(myplugin MODULE myplugin.cpp)
target_link_libraries(myplugin Qt5::Core mydependency)
set_property(TARGET myplugin PROPERTY AUTOMOC ON)

add_library(otherplugin MODULE otherplugin.cpp)
target_link_libraries(otherplugin Qt5::Core mydependency)
set_property(TARGET otherplugin PROPERTY AUTOMOC ON)
