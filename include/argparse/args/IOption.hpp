/**
 * @file IOption.hpp
 * @brief Declaration of abstract CLI option
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026 \n
 * MIT License: this software may be freely used, modified,
 * and distributed, provided that this notice is retained.
 */
#pragma once
#include "../api.hpp"
#include "IArgument.hpp"

#include <list>
#include <string>



namespace argparse {
    namespace args {
        /**
         * @typedef std::list<std::string> Flags
         * @brief Either a name or a list of option strings.
         * @details Using for store option flags
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        using Flags = std::list<std::string>;

        /**
         * @class IOption
         * @brief Basic class for CLI option
         * @details Contains definition and basic parameters of CLI options
         *
         * @warning This is an abstract class. Don't create its instances directly!
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        class ARGPARSE_API IOption: public IArgument {
        public:
        //* Ctors and dtor
            /**
             * @brief Default constructor
             * @details Creates new instance
             *
             * @param[in] FlagsList A list of option strings
             * @param[in] Help A brief description of what the argument does
             * @param[in] NArgs The number of command-line arguments that should be consumed.
             * See args::NARGS for special values
             *
             * @param[in] IsRequired Whether or not the command-line option may be omitted
             * @param[in] IsDeprecated Whether or not use of the argument is deprecated
             *
             * @throw std::bad_alloc in case of memory allocation failure
             * @throw inherited from args::IArgument(const std::string &, int, bool)
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            IOption(
                const Flags &FlagsList,
                const std::string &Help = "",
                int NArgs               = NARGS::NO_MORE,
                bool IsRequired         = false,
                bool IsDeprecated       = false
            );

            /**
             * @brief Default constructor
             * @details Creates new instance. \n
             * This constructor is appliable to initializers:
             * @code {.cpp}
             *     IOption(
             *         {"-a", "--arg"},
             *         "Help message",
             *         NARGS::NO_MORE,
             *         false, false
             *     )
             * @endcode
             *
             * @param[in] FlagsList A list of option strings
             * @param[in] Help A brief description of what the argument does
             * @param[in] NArgs The number of command-line arguments that should be consumed.
             * See args::NARGS for special values
             *
             * @param[in] IsRequired Whether or not the command-line option may be omitted
             * @param[in] IsDeprecated Whether or not use of the argument is deprecated
             *
             * @throw std::bad_alloc in case of memory allocation failure
             * @throw inherited from args::IArgument(const std::string &, int, bool)
             *
             * @warning This constructor invokes std::move on FlagsList
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            IOption(
                Flags &&FlagsList,
                const std::string &Help = "",
                int NArgs               = NARGS::NO_MORE,
                bool IsRequired         = false,
                bool IsDeprecated       = false
            );

            /**
             * @brief Copy constructor
             * @details Creates new instance as a copy of Other
             *
             * @param[in] Other Instance to copy
             *
             * @throw std::bad_alloc in case of memory allocation failure
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            IOption(const IOption &Other);

            /**
             * @brief Move constructor
             * @details Creates new instance moving Other
             *
             * @param[in] Other Instance to move
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            IOption(IOption &&Other) noexcept;

            /**
             * @brief Destroies instance
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual ~IOption() noexcept = 0;

        //* Operators
            /**
             * @brief Copy assignment operator
             * @details Copies Right instance to current one
             *
             * @param[in] Right Instance to copy
             * @returns Reference to current instance
             *
             * @throw std::bad_alloc in case of memory allocation failure
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            IOption &operator = (const IOption &Right);

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
            IOption &operator = (IOption &&Right) noexcept;

            /**
             * @brief Compares options flags
             *
             * @param[in] Right Option to compare
             * @returns true if options have at least one same flag
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            bool operator == (const IOption &Right) const;

            /**
             * @brief Compares options flags
             *
             * @param[in] Right Option to compare
             * @returns true if options have no same flags
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            bool operator != (const IOption &Right) const;

        //* Getters and setters
            /**
             * @brief Returns true if the option is required; false if not
             * @return Boolean value
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual bool isRequired() const;

            /**
             * @brief Makes option required or not
             * @param[in] IsRequired Boolean value. Default: true
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual void setRequired(bool IsRequired = true);

            /**
             * @brief Get argument flags
             * @details Returns a list of option strings.
             *
             * @return A list of option strings
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual const Flags &getFlags() const;

            /**
             * @brief Set argument flags
             * @details Sets a list of option strings
             *
             * @param[in] FlagsList A list of option strings
             *
             * @throw std::bad_alloc in case of memory allocation failure
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual void setFlags(const Flags &FlagsList);

            /**
             * @brief Set argument flags
             * @details Sets a list of option strings
             *
             * @param[in] FlagsList A list of option strings
             *
             * @warning This method invokes std::move on FlagsList
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual void setFlags(Flags &&FlagsList);

        //* etc
            bool isEquals(const IOption &Other) const;

            bool isMatch(const std::string &Opt) const;

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
            void selfCopy(const IOption &Other);

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
            void selfMove(IOption &&Other) noexcept;

        //* Variables
            bool  mIsRequired;      ///< Whether or not the command-line option may be omitted
            Flags mFlags;           ///< A list of option strings
        };
    }
}
