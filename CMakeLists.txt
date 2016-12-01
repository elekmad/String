cmake_minimum_required(VERSION 2.8)
#Déclaration du projet
cmake_policy(SET CMP0004 OLD)
project(Strings)
enable_testing()

add_library(Strings STATIC String.c String.h)
include_directories(Strings ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-D_GNU_SOURCE)
if(NOT EXTERNAL_PROJECT)
    # Thanks to http://neyasystems.com/an-engineers-guide-to-unit-testing-cmake-and-boost-unit-tests/ for this part
    #Setup CMake to run tests
    enable_testing()
    
    #I like to keep test files in a separate source directory called test
    file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} tests/*.c)
    
    #Run through each source
    foreach(testSrc ${TEST_SRCS})
            #Extract the filename without an extension (NAME_WE)
            get_filename_component(testName ${testSrc} NAME_WE)
    
            #Add compile target
            add_executable(${testName} ${testSrc})
    
            #link to Boost libraries AND your targets and dependencies
            target_link_libraries(${testName} Strings)
    
            #I like to move testing binaries into a testBin directory
            set_target_properties(${testName} PROPERTIES 
                RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/testBin)
    
            #Finally add it to test execution - 
            #Notice the WORKING_DIRECTORY and COMMAND
            add_test(NAME ${testName} 
                     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testBin 
                     COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/testBin/${testName} )
    endforeach(testSrc)

    # Thanks to https://tty1.net/blog/2014/cmake-doxygen_en.html for this part
    # add a target to generate API documentation with Doxygen
    find_package(Doxygen)
    option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})
    
    if(BUILD_DOCUMENTATION)
        if(NOT DOXYGEN_FOUND)
            message(FATAL_ERROR "Doxygen is needed to build the documentation.")
        endif()
    
        set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
        set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    
        configure_file(${doxyfile_in} ${doxyfile} @ONLY)
    
        add_custom_target(doc
            COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
    
        install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc)
    endif()

endif()

if( WITH_COREDEBUG )
  add_definitions(-ggdb3)
  message(STATUS "GCC: Debug-flags set (-ggdb3)")
endif()
