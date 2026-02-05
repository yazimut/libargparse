/**
 * @file IOptionalArgument.hpp
 * @brief Declaration of abstract optional CLI argument
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
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
         * @details Using for store arguments flags
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        using Flags = std::list<std::string>;

        /**
         * @class IOptionalArgument
         * @brief Abstract basic class for optional CLI arguments
         * @details Contains definition and basic parameters of optional CLI argument
         *
         * @warning This is an abstract class. Don't create its instances directly!
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        ARGPARSE_API class IOptionalArgument: public IArgument {
        public:
        //* Ctors and dtor
            /**
             * @brief Default constructor
             * @details Creates new instance of optional CLI argument
             *
             * @param[in] FlagsList A list of option strings
             * @param[in] Help A brief description of what the argument does
             * @param[in] NArgs The number of command-line arguments that should be consumed.
             * See args::NARGS for special values
             *
             * @param[in] IsRequired Whether or not the command-line option may be omitted (optionals only)
             * @param[in] IsDeprecated Whether or not use of the argument is deprecated
             *
             * @throw std::bad_alloc in case of memory allocation failure
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            IOptionalArgument(
                const Flags &FlagsList,
                const std::string &Help = "",
                uint32_t NArgs = NARGS::NO_MORE,
                bool IsRequired = false,
                bool IsDeprecated = false
            );

            /**
             * @brief Default constructor
             * @details Creates new instance of optional CLI argument.\n
             * This constructor is appliable to initializers:
             * @code {.cpp}
             *     IOptionalArgument(
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
             * @param[in] IsRequired Whether or not the command-line option may be omitted (optionals only)
             * @param[in] IsDeprecated Whether or not use of the argument is deprecated
             *
             * @throw std::bad_alloc in case of memory allocation failure
             *
             * @warning This constructor invokes std::move on FlagsList
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            IOptionalArgument(
                Flags &&FlagsList,
                const std::string &Help = "",
                uint32_t NArgs = NARGS::NO_MORE,
                bool IsRequired = false,
                bool IsDeprecated = false
            );

            /**
             * @brief Copy constructor
             * @details Creates new instance of optional CLI argument as a copy of Other
             *
             * @param[in] Other Instance to copy
             *
             * @throw std::bad_alloc in case of memory allocation failure
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            IOptionalArgument(const IOptionalArgument &Other);

            /**
             * @brief Move constructor
             * @details Creates new instance of optional CLI argument moving Other
             *
             * @param[in] Other Instance to move
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            IOptionalArgument(IOptionalArgument &&Other) noexcept;

            /**
             * @brief Destroies instance of optional CLI argument
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual ~IOptionalArgument() noexcept = 0;

        //* Getters and setters
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
            void selfCopy(const IOptionalArgument &Other);

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
            void selfMove(IOptionalArgument &&Other) noexcept;

        //* Variables
            Flags mFlags;             ///< A list of option strings
        };
    }
}
