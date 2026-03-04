cmake_minimum_required(VERSION 3.13)
set(PROJECT test_app)
project(${PROJECT} CXX)
set(TARGET ${PROJECT})
message(STATUS "Configuring ${PROJECT}")



set(CMAKE_CXX_FLAGS_DEBUG "")
set(CMAKE_CXX_FLAGS_RELEASE "")



file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${TARGET}
    ${SOURCES} ${HEADERS}
)
target_include_directories(${TARGET}
    PUBLIC
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_definitions(${TARGET}
    PUBLIC
    PRIVATE
        $<$<CONFIG:Debug>:DEBUG> $<$<CONFIG:Release>:NDEBUG>
)
target_compile_options(${TARGET}
    PUBLIC
    PRIVATE
        $<$<CONFIG:Debug>:-g3 -Og> $<$<CONFIG:Release>:-g0 -O3>
        -Wall -Wextra -Wpedantic $<$<CONFIG:Release>:-Werror -Wno-error=deprecated>
        -std=c++11 -pipe
)
target_link_directories(${TARGET} PUBLIC PRIVATE)
target_link_libraries(${TARGET}
    PUBLIC
        argparse
    PRIVATE
)
target_link_options(${TARGET}
    PUBLIC
    PRIVATE
        -s
)
