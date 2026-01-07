/**
 * @file api.hpp
 * @brief Declaration of library API export/import
 * @details Each header of libargparse includes this file.
 * Contains:
 *   * C++ standard checking;
 *   * Definitions of API macros;
 *   * First and global definition of libargparse namespace.
 *
 * @version 1.0.0
 * @date 2026-01-07
 * @authors Eugene Azimut (y.azimut@mail.ru)
 * @copyright Copyright (c) Eugene Azimut, 2026
 *
 */
#pragma once

#if !defined(__cplusplus)
    #error "Required language is C++"
#endif

#if __cplusplus < 201103L
    #error "Required C++ standard is C++11 and higher"
#endif

/** @cond IGNORE */
#if defined(_WIN32)
    // Microsoft Windows
    #if defined(ARGPARSE_STATIC)
        #define ARGPARSE_API
    #else
        #if !defined(ARGPARSE_SHARED)
            #define ARGPARSE_SHARED
        #endif

        #if defined(ARGPARSE_EXPORTS)
            #define ARGPARSE_API __declspec(dllexport)
        #else
            #define ARGPARSE_API __declspec(dllimport)
        #endif
    #endif

    #define ARGPARSE_HIDDEN
    #define ARGPARSE_DEPRECATED(msg) __declspec(deprecated(msg))
#else
    // Linux,
    // MacOS (OS X),
    // Android,
    // iOS,
    // Unix-like
    #if defined(ARGPARSE_STATIC)
        #define ARGPARSE_API
        #define ARGPARSE_HIDDEN
    #else
        #if !defined(ARGPARSE_SHARED)
            #define ARGPARSE_SHARED
        #endif

        #if defined(ARGPARSE_EXPORTS)
            #define ARGPARSE_API __attribute__((visibility("default")))
            #define ARGPARSE_HIDDEN __attribute__((visibility("hidden")))
        #else
            #define ARGPARSE_API
            #define ARGPARSE_HIDDEN
        #endif
    #endif

    #define ARGPARSE_DEPRECATED(msg) __attribute__((deprecated(msg)))
#endif
/** @endcond */



/**
 * @namespace argparse
 * @brief libargparse namespace
 * @details Contains all library definitions
 *
 * @authors Eugene Azimut
 * @version 1.0.0
 *
 */
namespace argparse {}
