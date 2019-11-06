cmake_minimum_required(VERSION 3.14)
project(ticket_recognition_jcpp)

if (LINUX_BUILD)
    set(BUILD_ENV "linux")
    set(LIB_TYPE "so")

    include_directories("$ENV{JAVA_HOME}/include/linux")
else(LINUX_BUID)
    set(BUILD_ENV "windows")
    set(LIB_TYPE "dll")

    include_directories("$ENV{JAVA_HOME}/include/win32")
endif (LINUX_BUILD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
include_directories("src/include")
include_directories("$ENV{JAVA_HOME}/include")

set(Ticket_Recognition_DIR "${ticket_recognition_jcpp_SOURCE_DIR}/libs/ticket_recognition")
find_package(ticket_recognition REQUIRED)
include_directories("${Ticket_Recognition_INCLUDE_DIRS}")

add_library(ticket_recognition_jcpp SHARED)

add_subdirectory(src)

target_link_libraries(ticket_recognition_jcpp ${Ticket_Recognition_LIBRARIES})

# Copy all libraries to binary folder
set(LIBRARY_BINARY_DIR ${PROJECT_BINARY_DIR}/libs)
file(MAKE_DIRECTORY ${LIBRARY_BINARY_DIR})

file(GLOB TICKET_RECOGNITION_ALL_LIBS "${Ticket_Recognition_DIR}/${BUILD_ENV}/bin/*.${LIB_TYPE}*")
file(COPY ${TICKET_RECOGNITION_ALL_LIBS} DESTINATION ${LIBRARY_BINARY_DIR})