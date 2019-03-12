cmake_minimum_required(VERSION 2.8)
#Déclaration du projet
project(Strings)

add_library(Strings STATIC String.c String.h)
include_directories(Strings ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-D_GNU_SOURCE)
# add unit tests in tests directory (make test to run)
set(testLink Strings)
include(unittests.cmake)
# add dpoxygen functionality
include(doxygen.cmake)

if( WITH_COREDEBUG )
  add_definitions(-ggdb3)
  message(STATUS "GCC: Debug-flags set (-ggdb3)")
endif()
