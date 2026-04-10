/**
 * @file NARGS.hpp
 * @brief Contains declaration of NARGS enum and functions
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026 \n
 * MIT License: this software may be freely used, modified,
 * and distributed, provided that this notice is retained.
 */
#pragma once
#include "../api.hpp"



namespace argparse {
    namespace args {
        /**
         * @brief Special values for NArgs parameter of CLI arguments
         * @details Contains special values for NArgs parameter. \n
         * Values: \n
         * * "NO_MORE"       - don't consume arguments \n
         * * "ZERO_OR_ONE"   - argument will consume 0 or 1 CLI argument, e.g. '?' \n
         * * "ZERO_AND_MORE" - argument will consume 0 or more CLI arguments, e.g. '*' \n
         * * "ONE_AND_MORE"  - argument will consume 1 or more CLI arguments, e.g. '+'
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        enum ARGPARSE_API NARGS: int {
            NO_MORE         = 0,     ///< Don't consume arguments
            ZERO_OR_ONE     = -1,    ///< Consume 0 or 1 argument
            ZERO_AND_MORE   = -2,    ///< Consume 0 or more arguments
            ONE_AND_MORE    = -3     ///< Consume 1 or more arguments
        };
    }
}
