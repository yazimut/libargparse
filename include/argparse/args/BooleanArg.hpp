/**
 * @file BooleanArg.hpp
 * @brief Declaration of boolean CLI argument
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#pragma once
#include "../api.hpp"
#include "IOptionalArgument.hpp"

#include <stdexcept>



namespace argparse {
    namespace args {
        /**
         * @class BooleanArg
         * @brief Contains definition and parameters of boolean CLI argument
         * @details This argument type is desired to store a command-line argument of a Boolean type.
         * It can be used in several scenarios:
         * 1. A flag that specifies a specific value through its presence (or absence)
         * 2. An argument that accepts a value from the user
         *
         * Examples:
         * 1. In code:
         *    @code {.cpp}
         *        BooleanArg(
         *            Output = MyVar,
         *            Flags = {"-f", "--flag"},
         *            Help = "My very important flag",
         *            NArgs = NARGS::NO_MORE,
         *            IsRequired = false,
         *            IsDeprecated = false,
         *            StoreValue = true
         *            DefaultValue = false
         *        );
         *    @endcode
         *    Command line:
         *    @code {.sh}
         *        ./my_prog --flag
         *    @endcode
         *    Result:
         *    @code
         *        MyVar = true
         *    @endcode
         *    In this example, presence of flag places in Myvar StoreValue.
         *    At the same time, absence of flag places in Myvar DefaultValue:\n
         *    Command line:
         *    @code {.sh}
         *        ./my_prog
         *    @endcode
         *    Result:
         *    @code
         *        MyVar = false
         *    @endcode
         *
         * 2. Now let's create an argument that allows user to set value by themself
         *    @code {.cpp}
         *        BooleanArg(
         *            Output = MyVar,
         *            Flags = {"-f", "--flag"},
         *            Help = "My very important flag",
         *            NArgs = NARGS::ZERO_OR_ONE,
         *            IsRequired = false,
         *            IsDeprecated = false,
         *            StoreValue = true
         *            DefaultValue = false
         *        );
         *    @endcode
         *    1. Command line:
         *       @code {.sh}
         *           ./my_prog --flag false
         *       @endcode
         *       Result:
         *       @code
         *           MyVar = false
         *       @endcode
         *    2. Command line:
         *       @code {.sh}
         *           ./my_prog --flag
         *       @endcode
         *       Result:
         *       @code
         *           MyVar = true
         *       @endcode
         *    3. Command line:
         *       @code {.sh}
         *           ./my_prog
         *       @endcode
         *       Result:
         *       @code
         *           MyVar = false
         *       @endcode
         *
         * Note the order in which the argument is processed:
         *   1. First, the presence of the value passed by the user is checked,
         *      and if it is present, that value is placed in Myvar
         *   2. Then, the argument behaves exactly as in example #1
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        ARGPARSE_API class BooleanArg: public IOptionalArgument {
        public:
        // Ctors and dtor
            /**
             * @brief Default constructor
             * @details Creates new instance of boolean CLI argument
             *
             * @param[out] Output Reference to a variable in which value will be placed
             * @param[in] FlagsList Either a name or a list of option strings
             * @param[in] Help A brief description of what the argument does
             * @param[in] NArgs The number of command-line arguments that should be consumed.\n
             * Available values:
             *   * 0;
             *   * 1;
             *   * NARGS::NO_MORE;
             *   * NARGS::ZERO_OR_ONE
             * @param[in] IsRequired Whether or not the command-line option may be omitted (optionals only)
             * @param[in] IsDeprecated Whether or not use of the argument is deprecated
             *
             * @param[in] StoreValue Value if flag recognized and value wasn't passed
             * @param[in] DefaultValue Default value if flag wasn't recognized
             *
             * @throw std::bad_alloc in case of memory allocation failure
             * @throw std::invalid_argument in case of invalid NArgs value
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            BooleanArg(
                bool &Output,

                const Flags &FlagsList,
                const std::string &Help = "",
                uint32_t NArgs = NARGS::NO_MORE,
                bool IsRequired   = false,
                bool IsDeprecated = false,

                bool StoreValue   = true,
                bool DefaultValue = false
            );

            /**
             * @brief Default constructor
             * @details Creates new instance of boolean CLI argument
             *
             * @param[out] Output Reference to a variable in which value will be placed
             * @param[in] FlagsList Either a name or a list of option strings.\n
             * This constructor is appliable to initializers:
             * @code {.cpp}
             *     BooleanArg(
             *         MyVar,
             *         {"-f", "--flag"},
             *         "Help message",
             *         NARGS::NO_MORE,
             *         false, false,
             *         true, false
             *     );
             * @endcode
             * @param[in] Help A brief description of what the argument does
             * @param[in] NArgs The number of command-line arguments that should be consumed.\n
             * Available values:
             *   * 0;
             *   * 1;
             *   * NARGS::NO_MORE;
             *   * NARGS::ZERO_OR_ONE
             * @param[in] IsRequired Whether or not the command-line option may be omitted (optionals only)
             * @param[in] IsDeprecated Whether or not use of the argument is deprecated
             *
             * @param[in] StoreValue Value if flag recognized and value wasn't passed
             * @param[in] DefaultValue Default value if flag wasn't recognized
             *
             * @throw std::bad_alloc in case of memory allocation failure
             * @throw std::invalid_argument in case of invalid NArgs value
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            BooleanArg(
                bool &Output,

                Flags &&FlagsList,
                const std::string &Help = "",
                uint32_t NArgs = NARGS::NO_MORE,
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
             * @param[in] Other Instance to move
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
            virtual ~BooleanArg() noexcept;

        // Getters and setters
            /**
             * @brief Set the number of command-line arguments that should be consumed
             * @param[in] NArgs The number of command-line arguments that should be consumed.\n
             * Available values:
             *   * 0;
             *   * 1;
             *   * NARGS::NO_MORE;
             *   * NARGS::ZERO_OR_ONE
             *
             * @throw std::invalid_argument in case of invalid NArgs value
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual void setNArgs(uint32_t NArgs) override;

            /**
             * @brief Returns the pointer to output variable
             * @return Pointer to output variable
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual bool *getOutput() const;

            /**
             * @brief Returns value if flag recognized and value wasn't passed
             * @return Value if flag recognized and value wasn't passed
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual bool getStoreValue() const;

            /**
             * @brief Sets value if flag recognized and value wasn't passed
             * @param[in] Value Value if flag recognized and value wasn't passed
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual void setStoreValue(bool Value);

            /**
             * @brief Returns default value if flag wasn't recognized
             * @return Default value if flag wasn't recognized
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual bool getDefaultValue() const;

            /**
             * @brief Sets default value if flag wasn't recognized
             * @param[in] Value Default value if flag wasn't recognized
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual void setDefaultValue(bool Value);

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
            void selfCopy(const BooleanArg &Other);

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
            void selfMove(BooleanArg &&Other) noexcept;

        //* Variables
            bool *mOutput;           ///< Pointer to a variable in which value will be placed
            bool  mStoreValue;       ///< Value if flag recognized and value wasn't passed
            bool  mDefaultValue;     ///< Default value if flag wasn't recognized
        };
    }
}
