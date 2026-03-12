/**
 * @file IArgumentParser.hpp
 * @brief Declaration of CLI arguments parser
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
    /**
     * @class IArgumentParser
     * @brief Abstract CLI arguments parser
     * @details Contains methods for parsing CLI arguments
     *
     * @warning This is an abstract class. Don't create its instances directly!
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    class ARGPARSE_API IArgumentParser {
    public:
    //* Ctors and dtor
        /**
         * @brief Default constructor
         * @details Creates new instance
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        IArgumentParser();

        /**
         * @brief Copy constructor
         * @details Creates new instance as a copy of Other
         *
         * @param[in] Other Instance to copy
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        IArgumentParser(const IArgumentParser &Other);

        /**
         * @brief Move constructor
         * @details Creates new instance moving Other
         *
         * @param[in, out] Other Instance to move
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        IArgumentParser(IArgumentParser &&Other) noexcept;

        /**
         * @brief Destroies instance
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual ~IArgumentParser() noexcept = 0;

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
        IArgumentParser &operator = (const IArgumentParser &Right);

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
        IArgumentParser &operator = (IArgumentParser &&Right) noexcept;

    //* etc
        virtual void addArgument();

        /**
         * @brief Parses given CLI arguments
         *
         * @param[in] argc Arguments count
         * @param[in] argv Arguments vector
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual void parse(int argc, const char *argv[]) const = 0;

    private:
        void selfCopy(const IArgumentParser &Other);
        void selfMove(IArgumentParser &&Other) noexcept;

    //* Variables
    };
}
