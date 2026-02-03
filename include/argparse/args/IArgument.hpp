/**
 * @file IArgument.hpp
 * @brief Declaration of abstract CLI argument
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#pragma once
#include "../api.hpp"
#include "NARGS.hpp"

#include <string>



namespace argparse {
    /**
     * @class IArgument
     * @brief Abstract basic class for CLI arguments
     * @details Contains definition and basic parameters of CLI argument
     *
     * @warning This is an abstract class. Don't create its instances directly!
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    ARGPARSE_API class IArgument {
    public:
    //* Ctors and dtor
        /**
         * @brief Default constructor
         * @details Creates new instance of CLI argument
         *
         * @param[in] Help A brief description of what the argument does
         * @param[in] NArgs The number of command-line arguments that should be consumed.
         * See argparse::NARGS for special values
         *
         * @param[in] IsRequired Whether or not the command-line option may be omitted (optionals only)
         * @param[in] IsDeprecated Whether or not use of the argument is deprecated
         *
         * @throw std::bad_alloc in case of memory allocation failure
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        IArgument(
            const std::string &Help = "",
            uint32_t NArgs = NARGS::NO_MORE,
            bool IsRequired = false,
            bool IsDeprecated = false
        );

        /**
         * @brief Copy constructor
         * @details Creates new instance of CLI argument as a copy of Other
         *
         * @param[in] Other Instance to copy
         *
         * @throw std::bad_alloc in case of memory allocation failure
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        IArgument(const IArgument &Other);

        /**
         * @brief Move constructor
         * @details Creates new instance of CLI argument moving Other
         *
         * @param[in] Other Instance to move
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        IArgument(IArgument &&Other) noexcept;

        /**
         * @brief Destroies instance of CLI argument
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual ~IArgument() = 0;

    //* Getters and setters
        /**
         * @brief Get help string
         * @details Returns a brief description of what the argument does.
         *
         * @return Help string
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual const char *getHelp() const;

        /**
         * @brief Set help string
         * @details Sets a new brief description of what the argument does.
         *
         * @param[in] Help New help message
         *
         * @throw std::bad_alloc in case of memory allocation failure
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual void setHelp(const std::string &Help);

        /**
         * @brief Get the number of command-line arguments that should be consumed
         * @return The number of command-line arguments that should be consumed
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual uint32_t getNArgs() const;

        /**
         * @brief Set the number of command-line arguments that should be consumed
         * @param[in] NArgs The number of command-line arguments that should be consumed
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual void setNArgs(uint32_t NArgs);

        /**
         * @brief Returns true if the argument is required; false if not
         * @return Boolean value
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual bool isRequired() const;

        /**
         * @brief Makes argument required or not
         * @param[in] IsRequired Boolean value. Default: true
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual void setRequired(bool IsRequired = true);

        /**
         * @brief Returns true if the argument is deprecated; false if not
         * @return Boolean value
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual bool isDeprecated() const;

        /**
         * @brief Makes argument deprecated or not
         * @param[in] IsDeprecated Boolean value. Default: true
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual void setDeprecated(bool IsDeprecated = true);

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
        void selfCopy(const IArgument &Other);

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
        void selfMove(IArgument &&Other) noexcept;

    //* Variables
        std::string mHelp;              ///< A brief description of what the argument does
        uint32_t    mNArgs;             ///< The number of command-line arguments that should be consumed
        bool        mIsRequired;        ///< Whether or not the command-line option may be omitted
        bool        mIsDeprecated;      ///< Whether or not use of the argument is deprecated
    };
}
