/**
 * @file version.hpp
 * @author Eugene Azimut (y.azimut@mail.ru)
 * @brief Declaration of library current version
 * @version 1.0.0
 * @date 2025-12-25
 *
 * @copyright Copyright (c) Eugene Azimut, 2025
 *
 */
#pragma once
#include "api.hpp"
#include <cstdint>
#include <cstddef>



namespace argparse {
    /**
     * @brief Library major update
     *
     * Can be [0;255]
     */
    constexpr uint32_t ARGPARSE_VERSION_MAJOR = 0 & 0xFF;

    /**
     * @brief Library minor update
     *
     * Can be [0;255]
     */
    constexpr uint32_t ARGPARSE_VERSION_MINOR = 1 & 0xFF;

    /**
     * @brief Library patch update
     *
     * Can be [0;65535]
     */
    constexpr uint32_t ARGPARSE_VERSION_PATCH = 0 & 0xFFFF;

    /**
     * @brief Library version number
     */
    constexpr uint32_t ARGPARSE_VERSION = (
        (ARGPARSE_VERSION_MAJOR << 24) |
        (ARGPARSE_VERSION_MINOR << 16) |
        (ARGPARSE_VERSION_PATCH)
    );

    /**
     * @brief Maximum size of library version string
     *
     */
    constexpr size_t MAX_ARGPARSE_VERSION_STRING_SIZE = 14;

    /**
     * @brief Get library version number
     * @return Version number
     */
    ARGPARSE_API uint32_t getVersionNumeric();

    /**
     * @brief Get library version string in format X.X.X
     * @return Version string
     */
    ARGPARSE_API const char *getVersionString();
}
