cmake_minimum_required(VERSION 2.8)
#Déclaration du projet
project(Strings)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_library(Strings STATIC String.c String.h)
include_directories(Strings ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-D_GNU_SOURCE)
# add unit tests in tests directory (make test to run)
set(testLink Strings)
include(unittests.cmake)
# add dpoxygen functionality
include(doxygen.cmake)

if(PROJECT_IS_TOP_LEVEL)
	find_package(Python3 REQUIRED)
	add_custom_target(proto
	    COMMAND ${Python3_EXECUTABLE}
	            ${CMAKE_SOURCE_DIR}/proto.py
	)
	add_dependencies(Strings proto)
endif()

if( WITH_COREDEBUG )
  add_definitions(-ggdb3)
  message(STATUS "GCC: Debug-flags set (-ggdb3)")
endif()
