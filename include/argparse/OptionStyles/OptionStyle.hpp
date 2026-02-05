/**
 * @file OptionStyle.hpp
 * @brief Declaration of basic CLI option style
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#pragma once
#include "../api.hpp"

#include <string>
#include <stdexcept>



namespace argparse {
    /**
     * @namespace argparse::OptStyles
     * @brief Contains all CLI option styles
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    namespace OptStyles {
        /**
         * @class OptionStyle
         * @brief Basic CLI option style
         * @details Contains definition and basic parameters of CLI option style
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        ARGPARSE_API class OptionStyle {
        public:
        //* Ctors and dtor
            /**
             * @brief Default constructor
             * @details Creates new instance of CLI option style
             *
             * @param[in] Indicator Option indicator.\n
             * See OptionStyle::setIndicator(const std::string &) for details
             * @param[in] ValueDelim Value delimiter.\n
             * See OptionStyle::setValueDelimiter(const std::string &) for details.\n
             * Default: ""
             *
             * @throw std::bad_alloc in case of memory allocation failure
             * @throw Exceptions from OptionStyle::setIndicator(const std::string &)
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            OptionStyle(
                const std::string &Indicator,
                const std::string &ValueDelim = ""
            );

            /**
             * @brief Copy constructor
             * @details Creates new instance of CLI option style as a copy of Other
             *
             * @param[in] Other Instance to copy
             *
             * @throw std::bad_alloc in case of memory allocation failure
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            OptionStyle(const OptionStyle &Other);

            /**
             * @brief Move constructor
             * @details Creates new instance of CLI option style moving Other
             *
             * @param[in] Other Instance to move
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            OptionStyle(OptionStyle &&Other) noexcept;

            /**
             * @brief Destroies instance of CLI option style
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual ~OptionStyle() noexcept;

        //* Getters and setters
            /**
             * @brief Get option indicator
             * @return Option indicator
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual const char *getIndicator() const;

            /**
             * @brief Set option indicator
             * @param[in] Value New option indicator. Cannot be an empty string
             *
             * @throw std::invalid_argument in case of empty Value
             * @throw std::bad_alloc in case of memory allocation failure
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual void setIndicator(const std::string &Value);

            /**
             * @brief Get value delimiter
             * @return Value delimiter
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual const char *getValueDelimiter() const;

            /**
             * @brief Set value delimiter
             * @param[in] Value New value delimiter.\n
             * Empty string marks no value can be provided.\n
             * Default: ""
             *
             * @throw std::bad_alloc in case of memory allocation failure
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual void setValueDelimiter(const std::string &Value = "");

        //* etc
            /**
             * @brief Checks if Arg is an option
             * @param[in] Arg Argument to be checked
             * @return true if Arg is an option, false if not
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual bool isArgOptional(const std::string &Arg) const;

            /**
             * @brief Splits Arg into Option and Value if possible
             * @details This method tries to split argument into Option and Value
             * using predefined indicator and delimiter.
             *
             * @note Strong exception guarantee!\n
             * Option and Value will not be touched in case of exceptions
             *
             * @param[in] Arg Argument to be splitted
             * @param[out] Option Option without indicator
             * @param[out] Value Value without delimiter
             *
             * @throw std::bad_alloc in case of memory allocation failure
             * TODO: ArgparseError
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual void splitArg(
                const std::string &Arg,
                std::string &Option,
                std::string &Value
            ) const;

        private:
            std::string mIndicator;     ///< Option indicator
            std::string mValueDelim;    ///< Value delimiter
        };
    }
}
