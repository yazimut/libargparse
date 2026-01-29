/**
 * @file version.hpp
 * @brief Declaration of library current version
 *
 * @version 1.0.0
 * @date 2026-01-07
 * @authors Eugene Azimut (y.azimut@mail.ru)
 * @copyright Copyright (c) Eugene Azimut, 2026
 *
 */
#pragma once
#include "api.hpp"

#include <cstddef>
#include <cstdint>



namespace argparse {
    /**
     * @brief Library major update
     *
     * Can be [0;255]
     *
     * @authors Eugene Azimut
     * @version 1.0.0
     */
    constexpr uint32_t ARGPARSE_VERSION_MAJOR = 1 & 0xFF;

    /**
     * @brief Library minor update
     *
     * Can be [0;255]
     *
     * @authors Eugene Azimut
     * @version 1.0.0
     */
    constexpr uint32_t ARGPARSE_VERSION_MINOR = 0 & 0xFF;

    /**
     * @brief Library patch update
     *
     * Can be [0;65535]
     *
     * @authors Eugene Azimut
     * @version 1.0.0
     */
    constexpr uint32_t ARGPARSE_VERSION_PATCH = 0 & 0xFFFF;

    /**
     * @brief Library version number
     *
     * @authors Eugene Azimut
     * @version 1.0.0
     */
    constexpr uint32_t ARGPARSE_VERSION = (
        (ARGPARSE_VERSION_MAJOR << 24) |
        (ARGPARSE_VERSION_MINOR << 16) |
        (ARGPARSE_VERSION_PATCH)
    );

    /**
     * @brief Maximum size of library version string
     *
     * @authors Eugene Azimut
     * @version 1.0.0
     *
     */
    constexpr size_t MAX_ARGPARSE_VERSION_STRING_SIZE = 14;

    /**
     * @brief Get library version number
     * @return Version number
     *
     * @authors Eugene Azimut
     * @version 1.0.0
     *
     */
    ARGPARSE_API uint32_t getVersionNumeric();

    /**
     * @brief Get library version string in format X.X.X
     * @return Version string
     * @throw std::bad_alloc in case of memory allocation failure
     *
     * @authors Eugene Azimut
     * @version 1.0.0
     */
    ARGPARSE_API const char *getVersionString();
}
