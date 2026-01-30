/**
 * @file version.hpp
 * @brief Declaration of library current version
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#pragma once
#include "api.hpp"

#include <cstddef>
#include <cstdint>



namespace argparse {
    /**
     * @brief Library major update
     * @details Can be [0;255]
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    constexpr uint32_t ARGPARSE_VERSION_MAJOR = 1 & 0xFF;

    /**
     * @brief Library minor update
     * @details Can be [0;255]
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    constexpr uint32_t ARGPARSE_VERSION_MINOR = 0 & 0xFF;

    /**
     * @brief Library patch update
     * @details Can be [0;65535]
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    constexpr uint32_t ARGPARSE_VERSION_PATCH = 0 & 0xFFFF;

    /**
     * @brief Numeric library version number
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    constexpr uint32_t ARGPARSE_VERSION = (
        (ARGPARSE_VERSION_MAJOR << 24) |
        (ARGPARSE_VERSION_MINOR << 16) |
        (ARGPARSE_VERSION_PATCH)
    );

    /**
     * @brief Maximum size of library version string
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    constexpr size_t MAX_ARGPARSE_VERSION_STRING_SIZE = 14;

    /**
     * @brief Get library version number
     * @return Version number
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    ARGPARSE_API uint32_t getVersionNumeric();

    /**
     * @brief Get library version string in format X.X.X
     * @return Version string
     *
     * @throw std::bad_alloc in case of memory allocation failure
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    ARGPARSE_API const char *getVersionString();
}
