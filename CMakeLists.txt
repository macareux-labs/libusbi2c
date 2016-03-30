### CMake file for usbi2c-linux
###
###
###   - Feb 2016: Initial version <bulot@macareux-labs.com>
###
###
###############################################################################


cmake_minimum_required (VERSION 2.6)

project (usbi2c)
set (usbi2c_VERSION_MAJOR 0)
set (usbi2c_VERSION_MINOR 1)

set( CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /lib /usr/lib /usr/local/lib )
set( CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} /usr/include /usr/local/include )

set( CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake" ) 

set ( INSTALL_BIN_PATH bin )
set ( INSTALL_LIB_PATH lib )
set ( INSTALL_AR_PATH  lib )
set ( INSTALL_HEADERS_PATH include )


# Make relative paths absolute (needed later on)

foreach(p LIB BIN HEADERS AR)
        set(var INSTALL_${p}_PATH)
        if(NOT IS_ABSOLUTE "${${var}}")
                set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
        endif()
endforeach()


### Search for Lib/Headers

include( GNUInstallDirs )

### Config File


configure_file ( "${PROJECT_SOURCE_DIR}/config.h.in"
		 "${PROJECT_SOURCE_DIR}/include/usbi2c/config.h" )


### Set include directories 
        
include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/include"
	             "${CMAKE_CURRENT_BINARY_DIR}" )

### File lists

file( GLOB src "src/*.c"  )
file( GLOB hdr "src/*.h"  "include/*.h" )


### Targets

add_library( "usbi2c" SHARED ${src} ${hdr} ) 


### Install 


install( TARGETS "usbi2c"
	    RUNTIME DESTINATION ${INSTALL_BIN_PATH}  COMPONENT main
	    LIBRARY DESTINATION ${INSTALL_LIB_PATH}  COMPONENT main
            ARCHIVE DESTINATION ${INSTALL_AR_PATH}   COMPONENT main )

### Call other CMakelists recursively

add_subdirectory( "tools" )
