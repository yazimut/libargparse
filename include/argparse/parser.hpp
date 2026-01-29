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
#include "args/IArgument.hpp"

#include <cstdint>



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
        /**
         * @brief Action on CLI arguments parsing errors
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        enum class ErrorAction: uint32_t {
            NOTHING = 0,    ///< No actions, skip error
            EXIT,           ///< Exit program
            EXCEPTION       ///< Throw exception
        };

        /**
         * @brief Default constructor
         * @details Creates new instance of CLI arguments parser
         *
         * @param[in] OnError Action on CLI arguments parsing errors.
         * Default value - EXIT
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        ArgumentParser(ErrorAction OnError = ErrorAction::EXIT);

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
         * @brief Destroies instance of CLI arguments parser
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual ~ArgumentParser();

        /**
         * @brief Copy assignment operator
         * @details Copies Right instance to the current one
         *
         * @param[in] Right Instance to copy
         * @return Reference to the current instance
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual ArgumentParser &operator = (const ArgumentParser &Right);

        /**
         * @brief Adds a new argument to parse
         * @details Adds new argument definition,
         * that will be used during parsing CLI arguments
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual void addArgument();

        /**
         * @brief Get action on CLI arguments parsing errors
         * @return Current action
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        ErrorAction getErrorAction() const;

        /**
         * @brief Set action on CLI arguments parsing errors
         * @param[in] OnError New action
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        void setErrorAction(ErrorAction OnError);

    private:
        ErrorAction mOnErrorAction;     ///< Action on CLI arguments parsing errors
    };
}
