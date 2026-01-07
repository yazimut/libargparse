/**
 * @file parser.hpp
 * @brief Declaration of CLI arguments parser
 *
 * @version 1.0.0
 * @date 2026-01-07
 * @authors Eugene Azimut (y.azimut@mail.ru)
 * @copyright Copyright (c) Eugene Azimut, 2026
 *
 */
#pragma once
#include "api.hpp"

namespace argparse {
    /**
     * @class ArgumentParser
     * @brief Contains methods for parsing CLI arguments
     *
     */
    class ARGPARSE_API ArgumentParser {
    public:
        /**
         * @brief Creates new instance of CLI arguments parser
         *
         */
        ArgumentParser();

        /**
         * @brief Destroies instance of CLI arguments parser
         *
         */
        virtual ~ArgumentParser();
    };
}
