cmake_minimum_required(VERSION 3.14)
project(ticket_recognition_jcpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
include_directories("src/include")
include_directories("$ENV{JAVA_HOME}/include")
include_directories("$ENV{JAVA_HOME}/include/win32")

set(Ticket_Recognition_DIR "${ticket_recognition_jcpp_SOURCE_DIR}/libs/ticket_recognition")
find_package(ticket_recognition REQUIRED)
include_directories("${Ticket_Recognition_INCLUDE_DIRS}")

add_library(ticket_recognition_jcpp SHARED)

add_subdirectory(src)

target_link_libraries(ticket_recognition_jcpp ${Ticket_Recognition_LIBRARIES})