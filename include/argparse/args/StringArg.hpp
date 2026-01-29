/**
 * @file StringArg.hpp
 * @brief Declaration of string CLI argument
 *
 * @version 1.0.0
 * @date 2026-01-29
 * @authors Eugene Azimut (y.azimut@mail.ru)
 * @copyright Copyright (c) Eugene Azimut, 2026
 *
 */
#pragma once
#include "../api.hpp"
#include "IArgument.hpp"



namespace argparse {
    /**
     * @class StringArg
     * @brief Class for string CLI arguments
     * @details Contains definition and parameters of string CLI argument
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    ARGPARSE_API class StringArg: public IArgument {
    public:
    // Ctors and dtor
        /**
         * @brief Default constructor
         * @details Creates new instance of string CLI argument
         *
         * @param[in] Flags Either a name or a list of option strings.
         * Options have to be separated by commas (','). Any whitespace will be ommited.
         * To mark argument as an optional use dash ('-') or double-dash ('--')
         *
         * @param[in] Help A brief description of what the argument does
         * @param[in] IsRequired Whether or not the command-line option may be omitted (optionals only)
         * @param[in] IsDeprecated Whether or not use of the argument is deprecated
         *
         * @throw std::bad_alloc in case of memory allocation failure
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        StringArg(
            const std::string &Flags,
            const std::string &Help = "",
            bool IsRequired = false,
            bool IsDeprecated = false
        );

        /**
         * @brief Copy constructor
         * @details Creates new instance of string CLI argument as a copy of Other
         *
         * @param[in] Other Instance to copy
         *
         * @throw std::bad_alloc in case of memory allocation failure
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        StringArg(const StringArg &Other);

        /**
         * @brief Move constructor
         * @details Creates new instance of string CLI argument moving Other
         *
         * @param[in,out] Other Instance to move
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        StringArg(StringArg &&Other) noexcept;

        /**
         * @brief Destroies instance of string CLI argument
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual ~StringArg();

    // Operators
        /**
         * @brief Copy assignment operator
         * @details Copies Right instance to the current one
         *
         * @param[in] Right Instance to copy
         * @return Reference to the current instance
         *
         * @throw std::bad_alloc in case of memory allocation failure
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        StringArg &operator = (const StringArg &Right);

        /**
         * @brief Move assignment operator
         * @details Moves Right instance to the current one
         *
         * @param[in,out] Right Instance to move
         * @return Reference to the current instance
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        StringArg &operator = (StringArg &&Right) noexcept;

    protected:
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
        void selfCopy(const StringArg &Other);

        /**
         * @brief Moves current class members
         * @details The method moves members of only the given class,
         * even if it is an inheritor, and lets avoid repeating code
         * in the move constructor and move assignment operator
         *
         * @param[in,out] Other Instance to move
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        void selfMove(StringArg &&Other) noexcept;

    private:
    };
}
