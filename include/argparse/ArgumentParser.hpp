/**
 * @file ArgumentParser.hpp
 * @brief Declaration of CLI arguments parser
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#pragma once
#include "api.hpp"

#include <string>



namespace argparse {
    /**
     * @class ArgumentParser
     * @brief Contains methods for parsing CLI arguments
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    ARGPARSE_API class ArgumentParser {
    public:
    //* Ctors and dtor
        /**
         * @brief Default constructor
         * @details Creates new instance of CLI arguments parser
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        ArgumentParser();

        /**
         * @brief Copy constructor
         * @details Creates new instance of CLI arguments parser as a copy of Other
         *
         * @param[in] Other Instance to copy
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        ArgumentParser(const ArgumentParser &Other);

        /**
         * @brief Move constructor
         * @details Creates new instance of CLI arguments parser moving Other
         *
         * @param[in] Other Instance to move
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        ArgumentParser(ArgumentParser &&Other) noexcept;

        /**
         * @brief Destroies instance of CLI arguments parser
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual ~ArgumentParser();

    //* etc
        virtual void parse(int argc, const char *argv[]);

    protected:
        virtual bool isArgOptional(const std::string &Arg) const;

        virtual void splitOption(
            const std::string &Arg,
            std::string &Option,
            std::string &Value
        ) const;

    private:
        /**
         * @brief Copies current class members
         * @details The method copies members of only the given class,
         * even if it is an inheritor, and lets avoid repeating code
         * in the copy constructor and copy assignment operator
         *
         * @param[in] Other Instance to copy
         *
         * @throw std::bad_alloc in case of memory allocation failure
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        void selfCopy(const ArgumentParser &Other);

        /**
         * @brief Moves current class members
         * @details The method moves members of only the given class,
         * even if it is an inheritor, and lets avoid repeating code
         * in the move constructor and move assignment operator
         *
         * @param[in] Other Instance to move
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        void selfMove(ArgumentParser &&Other) noexcept;

    //* Variables
    };
}
