/**
 * @file NARGS.hpp
 * @brief Contains declaration of NARGS enum and functions
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#pragma once
#include "../api.hpp"

#include <cstdint>
#include <string>



namespace argparse {
    namespace args {
        /**
         * @brief Special values for NArgs parameter of CLI arguments
         * @details Contains special values for NArgs parameter.\n
         * Values:\n
         * * "NO_MORE"       - don't consume arguments\n
         * * "ZERO_OR_ONE"   - argument will consume 0 or 1 CLI argument, e.g. '?' in python.argparse\n
         * * "ZERO_AND_MORE" - argument will consume 0 or more CLI arguments, e.g. '*' in python.argparse\n
         * * "ONE_AND_MORE"  - argument will consume 1 or more CLI arguments, e.g. '+' in python.argparse
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        ARGPARSE_API enum NARGS: uint32_t {
            NO_MORE         = 0u,                ///< Don't consume arguments
            ZERO_OR_ONE     = UINT32_MAX - 0u,   ///< Consume 0 or 1 arguments
            ZERO_AND_MORE   = UINT32_MAX - 1u,   ///< Consume 0 or more arguments
            ONE_AND_MORE    = UINT32_MAX - 2u    ///< Consume 1 or more arguments
        };

        /**
         * @brief Converts NARGS value into string representation
         * @details Converts NARGS value into string representation:\n
         *   * All values from args::NARGS will be converted using their names
         *   * Another values will be converted as their integer values
         *
         * @param[in] Value Value to be converted
         * @return String representation of Value
         */
        ARGPARSE_API std::string to_string(uint32_t Value);
    }
}
