cmake_minimum_required(VERSION 3.28.3)
project(libargparse CXX)
set(PROJECT libargparse)
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
    message(STATUS "Project configuration: ${CMAKE_BUILD_TYPE}")
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
    set(ARGPARSE_LIB_TYPE SHARED)
    message(STATUS "ARGPARSE_LIB_TYPE wasn't set, using default: ${ARGPARSE_LIB_TYPE}")
endif()

if(ARGPARSE_LIB_TYPE MATCHES "STATIC|SHARED|ALL")
    message(STATUS "Lib type: ${ARGPARSE_LIB_TYPE}")

    if(ARGPARSE_LIB_TYPE STREQUAL "ALL")
        set(NO_TEST_APP ON CACHE BOOL "Don't build test_app" FORCE)

        if(NOT DEFINED TESTS)
            set(TESTS ON CACHE BOOL "Build and run tests" FORCE)
        endif()
    endif()
else()
    message(FATAL_ERROR "invalid ARGPARSE_LIB_TYPE: ${ARGPARSE_LIB_TYPE}. Available: STATIC, SHARED or ALL")
endif()



### Target
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(GLOBAL_PUBLIC_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(GLOBAL_CXX_DEFINES
    $<$<CONFIG:Debug>:DEBUG> $<$<CONFIG:Release>:NDEBUG>
)
set(GLOBAL_CXX_OPTIONS
    $<$<CONFIG:Debug>:-g3 -Og> $<$<CONFIG:Release>:-g0 -O3>
    -Wall -Wextra -Wpedantic $<$<CONFIG:Release>:-Werror>
    -std=c++11
)
set(GLOBAL_LINK_OPTIONS)
set(GLOBAL_LINK_DIRS)
set(GLOBAL_LINK_LIBS)

if((ARGPARSE_LIB_TYPE STREQUAL "STATIC") OR (ARGPARSE_LIB_TYPE STREQUAL "ALL"))
    set(TARGET ${GLOBAL_LIB_NAME}_static)
    add_library(${TARGET} STATIC ${SOURCES} ${HEADERS})
    target_include_directories(${TARGET} PUBLIC ${GLOBAL_PUBLIC_INCLUDES})
    target_compile_definitions(${TARGET} PRIVATE
        ${GLOBAL_CXX_DEFINES}
        ARGPARSE_STATIC
    )
    target_compile_options(${TARGET} PRIVATE
        ${GLOBAL_CXX_OPTIONS}
    )
    target_link_options(${TARGET} PRIVATE ${GLOBAL_LINK_OPTIONS})
    target_link_directories(${TARGET} PUBLIC ${GLOBAL_LINK_DIRS})
    target_link_libraries(${TARGET} PUBLIC ${GLOBAL_LINK_LIBS})
    set_target_properties(${TARGET} PROPERTIES OUTPUT_NAME "${GLOBAL_LIB_NAME}")
endif()

if((ARGPARSE_LIB_TYPE STREQUAL "SHARED") OR (ARGPARSE_LIB_TYPE STREQUAL "ALL"))
    set(TARGET ${GLOBAL_LIB_NAME}_shared)
    add_library(${TARGET} SHARED ${SOURCES} ${HEADERS})
    target_include_directories(${TARGET} PUBLIC ${GLOBAL_PUBLIC_INCLUDES})
    target_compile_definitions(${TARGET} PRIVATE
        ${GLOBAL_CXX_DEFINES}
        ARGPARSE_STATIC
    )
    target_compile_options(${TARGET} PRIVATE
        ${GLOBAL_CXX_OPTIONS}
        -fvisibility=hidden
    )
    target_link_options(${TARGET} PRIVATE ${GLOBAL_LINK_OPTIONS})
    target_link_directories(${TARGET} PUBLIC ${GLOBAL_LINK_DIRS})
    target_link_libraries(${TARGET} PUBLIC ${GLOBAL_LINK_LIBS})
    set_target_properties(${TARGET} PROPERTIES OUTPUT_NAME "${GLOBAL_LIB_NAME}")
endif()



if((NOT DEFINED NO_TEST_APP) OR (NOT NO_TEST_APP))
    message(STATUS "Build test_app: YES")
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests/test_app")
else()
    message(STATUS "Build test_app: NO")
endif()

# if(TESTS)
#     message(STATUS "Build and run tests: YES")
# else()
#     message(STATUS "Build and run tests: NO")
# endif()
