cmake_minimum_required(VERSION 3.28.3)
set(PROJECT libargparse)
project(${PROJECT} CXX)
set(GLOBAL_LIB_NAME argparse)
message(STATUS "Configuring ${PROJECT}")

if(
    NOT DEFINED CMAKE_BUILD_TYPE OR
    CMAKE_BUILD_TYPE STREQUAL ""
)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build configuration" FORCE)
    message(STATUS "CMAKE_BUILD_TYPE wasn't set, using default: ${CMAKE_BUILD_TYPE}")
endif()

if(CMAKE_BUILD_TYPE MATCHES "Debug|Release")
    message(STATUS "${GLOBAL_LIB_NAME} configuration: ${CMAKE_BUILD_TYPE}")
else()
    message(FATAL_ERROR "invalid CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}. Available: Debug or Relase")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "")
set(CMAKE_CXX_FLAGS_RELEASE "")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})



### Lib type
if(NOT DEFINED ARGPARSE_LIB_TYPE)
    set(ARGPARSE_LIB_TYPE STATIC)
    message(STATUS "ARGPARSE_LIB_TYPE wasn't set, using default: ${ARGPARSE_LIB_TYPE}")
endif()

if(ARGPARSE_LIB_TYPE MATCHES "STATIC|SHARED")
    message(STATUS "${GLOBAL_LIB_NAME} type: ${ARGPARSE_LIB_TYPE}")
else()
    message(FATAL_ERROR "invalid ARGPARSE_LIB_TYPE: ${ARGPARSE_LIB_TYPE}. Available: STATIC or SHARED")
endif()



### Extract lib version
# Read version file
set(VERSION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/include/${GLOBAL_LIB_NAME}/version.hpp")
if(NOT EXISTS ${VERSION_FILE})
    message(FATAL_ERROR "${GLOBAL_LIB_NAME} (or include/${GLOBAL_LIB_NAME}/version.hpp) hasn't been found!")
endif()
file(READ ${VERSION_FILE} VERSION_FILE_CONTENT)

# Extract version
string(REGEX MATCH "ARGPARSE_VERSION_MAJOR = ([0-9]+)" _ ${VERSION_FILE_CONTENT})
set(ARGPARSE_VERSION_MAJOR ${CMAKE_MATCH_1})

string(REGEX MATCH "ARGPARSE_VERSION_MINOR = ([0-9]+)" _ ${VERSION_FILE_CONTENT})
set(ARGPARSE_VERSION_MINOR ${CMAKE_MATCH_1})

string(REGEX MATCH "ARGPARSE_VERSION_PATCH = ([0-9]+)" _ ${VERSION_FILE_CONTENT})
set(ARGPARSE_VERSION_PATCH ${CMAKE_MATCH_1})

# Concatenation
set(ARGPARSE_VERSION "${ARGPARSE_VERSION_MAJOR}.${ARGPARSE_VERSION_MINOR}.${ARGPARSE_VERSION_PATCH}")
message(STATUS "${GLOBAL_LIB_NAME} version: ${ARGPARSE_VERSION}")



### Target
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(PUBLIC_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CXX_DEFINES
    $<$<CONFIG:Debug>:DEBUG> $<$<CONFIG:Release>:NDEBUG>
    ARGPARSE_EXPORTS
)
set(CXX_OPTIONS
    $<$<CONFIG:Debug>:-g3 -Og> $<$<CONFIG:Release>:-g0 -O3>
    -Wall -Wextra -Wpedantic $<$<CONFIG:Release>:-Werror>
    -std=c++11
)
set(LINK_OPTIONS)
set(LINK_DIRS)
set(LINK_LIBS)



if(ARGPARSE_LIB_TYPE STREQUAL "STATIC")
    set(CXX_DEFINES
        ${CXX_DEFINES}
        ARGPARSE_STATIC
    )
elseif(ARGPARSE_LIB_TYPE STREQUAL "SHARED")
    set(CXX_DEFINES
        ${CXX_DEFINES}
        ARGPARSE_SHARED
    )
    set(CXX_OPTIONS
        ${CXX_OPTIONS}
        -fvisibility=hidden
    )
endif()

set(TARGET ${GLOBAL_LIB_NAME})
add_library(${TARGET} ${ARGPARSE_LIB_TYPE} ${SOURCES} ${HEADERS})
target_include_directories(${TARGET} PUBLIC ${PUBLIC_INCLUDES})
target_compile_definitions(${TARGET} PRIVATE ${CXX_DEFINES})
target_compile_options(${TARGET} PRIVATE ${CXX_OPTIONS})
target_link_options(${TARGET} PRIVATE ${LINK_OPTIONS})
target_link_directories(${TARGET} PUBLIC ${LINK_DIRS})
target_link_libraries(${TARGET} PUBLIC ${LINK_LIBS})
set_target_properties(${TARGET} PROPERTIES
    VERSION     ${ARGPARSE_VERSION}
    SOVERSION   ${ARGPARSE_VERSION_MAJOR}
)



add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests/test_app")
