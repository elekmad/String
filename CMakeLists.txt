cmake_minimum_required(VERSION 2.8)
#Déclaration du projet
project(Strings)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB CPP_SOURCE
        ./*.h
        ./*.c
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/" FILES ${CPP_SOURCE})
add_library(Strings ${CPP_SOURCE})
include_directories(Strings ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-D_GNU_SOURCE)
# add unit tests in tests directory (make test to run)
set(testLink Strings)
include(unittests.cmake)
# add dpoxygen functionality
include(doxygen.cmake)

find_package(Python3 REQUIRED)

foreach(source ${CPP_SOURCE})
	if(${source} MATCHES "\\.c$")
		message(STATUS ${source}" must gen proto")
		string(REGEX REPLACE "\\.c$" ".h" header "${source}")
		if(NOT EXISTS "${header}")
		message(STATUS ${header}" do not exist")
	        continue()
    	endif()
    	file(READ "${header}" HEADER_CONTENT)

    	if(HEADER_CONTENT MATCHES "#[ \t]*include[ \t]*<[^<]*\\.proto\\.h>")
    		string(REGEX REPLACE "\\.c$" ".proto.h" pheader "${source}")
    		message(STATUS ${pheader}" must be gen produced")
         	add_custom_command(
			    	OUTPUT
    				${pheader}
					COMMAND ${Python3_EXECUTABLE}
            			${CMAKE_SOURCE_DIR}/proto.py ${CPROTO_INCLUDES} --source ${source} --compile ${CMAKE_SOURCE_DIR}
    				DEPENDS ${source}
					)
			set_source_files_properties(
    				${source}
    				PROPERTIES
        			OBJECT_DEPENDS ${pheader}
			)
		else()
			message(STATUS ${header}" do not contain proto")
    	endif()
	endif()
endforeach()

if(NOT PROJECT_IS_TOP_LEVEL)
	list(APPEND CPROTO_INCLUDES "--include" "${CMAKE_CURRENT_SOURCE_DIR}")
	set(CPROTO_INCLUDES "${CPROTO_INCLUDES}" PARENT_SCOPE)
	message(STATUS "cproto includes : ${CPROTO_INCLUDES}")
endif()

if( WITH_COREDEBUG )
  add_definitions(-ggdb3)
  message(STATUS "GCC: Debug-flags set (-ggdb3)")
endif()
