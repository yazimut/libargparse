cmake_minimum_required(VERSION 3.28.3)
project(libargparse CXX)
set(PROJECT libargparse)
set(TARGET argparse)
message(STATUS "Configuring ${PROJECT}")

if(
    NOT DEFINED CMAKE_BUILD_TYPE OR
    CMAKE_BUILD_TYPE STREQUAL ""
)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build configuration" FORCE)
    message(WARNING "CMAKE_BUILD_TYPE wasn't set, using default: ${CMAKE_BUILD_TYPE}")
endif()

if(CMAKE_BUILD_TYPE MATCHES "Debug|Release")
    message(STATUS "Project configuration: ${CMAKE_BUILD_TYPE}")
else()
    message(FATAL_ERROR "invalid CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}. Available: Debug or Relase")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "")
set(CMAKE_CXX_FLAGS_RELEASE "")



file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${TARGET} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${TARGET} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_definitions(${TARGET} PRIVATE
    $<$<CONFIG:Debug>:DEBUG> $<$<CONFIG:Release>:NDEBUG>
    ARGPARSE_EXPORTS
    ARGPARSE_STATIC
)
target_compile_options(${TARGET} PRIVATE
    $<$<CONFIG:Debug>:-g3 -Og> $<$<CONFIG:Release>:-g0 -O3>
    -Wall -Wextra -Wpedantic $<$<CONFIG:Release>:-Werror>
    -std=c++11
    -fvisibility=hidden
)
target_link_options(${TARGET} PRIVATE)
target_link_directories(${TARGET} PUBLIC)
target_link_libraries(${TARGET} PUBLIC)



if(NOT DEFINED NO_TEST_APP)
    message(STATUS "Build test_app: YES")
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests/test_app")
else()
    message(STATUS "Build test_app: NO")
endif()

# if(NOT DEFINED NO_TESTS)
#     message(STATUS "Build and run tests: YES")
# else()
#     message(STATUS "Build and run tests: NO")
# endif()
