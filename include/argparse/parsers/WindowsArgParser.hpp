/**
 * @file WindowsArgParser.hpp
 * @brief Declaration of Windows-style CLI arguments parser
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026 \n
 * MIT License: this software may be freely used, modified,
 * and distributed, provided that this notice is retained.
 */
#pragma once
#include "../api.hpp"
#include "IArgumentParser.hpp"



namespace argparse {
    /**
     * @class WindowsArgParser
     * @brief Windows-style CLI arguments parser
     * @details Contains methods for parsing CLI arguments
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    class ARGPARSE_API WindowsArgParser: public IArgumentParser {
    public:
    //* Ctors and dtor
        /**
         * @brief Default constructor
         * @details Creates new instance
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        WindowsArgParser();

        /**
         * @brief Copy constructor
         * @details Creates new instance as a copy of Other
         *
         * @param[in] Other Instance to copy
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        WindowsArgParser(const WindowsArgParser &Other);

        /**
         * @brief Move constructor
         * @details Creates new instance moving Other
         *
         * @param[in, out] Other Instance to move
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        WindowsArgParser(WindowsArgParser &&Other) noexcept;

        /**
         * @brief Destroies instance
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual ~WindowsArgParser() noexcept;

    //* Operators
        /**
         * @brief Copy assignment operator
         * @details Copies Right instance to current one
         *
         * @param[in] Right Instance to copy
         * @returns Reference to current instance
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        WindowsArgParser &operator = (const WindowsArgParser &Right);

        /**
         * @brief Move assignment operator
         * @details Moves Right instance to current one
         *
         * @param[in] Right Instance to move
         * @returns Reference to current instance
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        WindowsArgParser &operator = (WindowsArgParser &&Right) noexcept;

    //* etc
        /**
         * @brief Parses given CLI arguments
         *
         * @param[in] argc Arguments count
         * @param[in] argv Arguments vector
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual void parse(int argc, const char *argv[]) const override;

    private:
        void selfCopy(const WindowsArgParser &Other);
        void selfMove(WindowsArgParser &&Other) noexcept;

    //* Variables
    };
}
