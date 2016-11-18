cmake_minimum_required(VERSION 2.8)
#Déclaration du projet
cmake_policy(SET CMP0004 OLD)
project(Strings)

add_library(Strings STATIC String.c String.h)
include_directories(Strings "./")

add_executable(Test main.c)
target_link_libraries(Test Strings)

if( WITH_COREDEBUG )
  add_definitions(-ggdb3)
  message(STATUS "GCC: Debug-flags set (-ggdb3)")
endif()
