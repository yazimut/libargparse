/**
 * @file BooleanArg.hpp
 * @brief Declaration of boolean CLI argument
 *
 * @version 1.0.0
 * @date 2026-01-30
 * @authors Eugene Azimut (y.azimut@mail.ru)
 * @copyright Copyright (c) Eugene Azimut, 2026
 *
 */
#pragma once
#include "../api.hpp"
#include "IArgument.hpp"



namespace argparse {
    /**
     * @class BooleanArg
     * @brief Class for boolean CLI arguments
     * @details Contains definition and parameters of boolean CLI argument
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    ARGPARSE_API class BooleanArg: public IArgument {
    public:
    // Ctors and dtor
        /**
         * @brief Default constructor
         * @details Creates new instance of boolean CLI argument
         *
         * @param[in] Flags Either a name or a list of option strings.
         * Options have to be separated by commas (','). Any whitespace will be ommited.
         * To mark argument as an optional use dash ('-') or double-dash ('--')
         *
         * @param[in] Help A brief description of what the argument does
         * @param[in] IsRequired Whether or not the command-line option may be omitted (optionals only)
         * @param[in] IsDeprecated Whether or not use of the argument is deprecated
         *
         * @param[in] StoreValue Value if flag recognized and value wasn't passed
         * @param[in] DefaultValue Default value if flag wasn't recognized
         *
         * @throw std::bad_alloc in case of memory allocation failure
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        BooleanArg(
            const std::string &Flags,
            const std::string &Help = "",
            bool IsRequired   = false,
            bool IsDeprecated = false,

            bool StoreValue   = true,
            bool DefaultValue = false
        );

        /**
         * @brief Copy constructor
         * @details Creates new instance of boolean CLI argument as a copy of Other
         *
         * @param[in] Other Instance to copy
         *
         * @throw std::bad_alloc in case of memory allocation failure
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        BooleanArg(const BooleanArg &Other);

        /**
         * @brief Move constructor
         * @details Creates new instance of boolean CLI argument moving Other
         *
         * @param[in,out] Other Instance to move
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        BooleanArg(BooleanArg &&Other) noexcept;

        /**
         * @brief Destroies instance of boolean CLI argument
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual ~BooleanArg();

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
        BooleanArg &operator = (const BooleanArg &Right);

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
        BooleanArg &operator = (BooleanArg &&Right) noexcept;

    // Getters and setters
        virtual bool getValue() const;

        virtual bool getStoreValue() const;
        virtual void setStoreValue(bool Value);

        virtual bool getDefaultValue() const;
        virtual void setDefaultValue(bool Value);

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
        void selfCopy(const BooleanArg &Other);

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
        void selfMove(BooleanArg &&Other) noexcept;

    private:
        bool mValue;            ///< Recognized value
        bool mStoreValue;       ///< Value if flag recognized and value wasn't passed
        bool mDefaultValue;     ///< Default value if flag wasn't recognized
    };
}
