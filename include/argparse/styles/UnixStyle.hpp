/**
 * @file UnixStyle.hpp
 * @brief Declaration of Unix CLI option style
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#pragma once
#include "../api.hpp"
#include "OptionStyle.hpp"



namespace argparse {
    namespace styles {
        /**
         * @class UnixStyle
         * @brief Unix CLI option style
         * @details Contains definition and basic parameters of CLI option style
         * that is typical for Unix-like systems
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        class ARGPARSE_API UnixStyle final: public OptionStyle {
        public:
        //* Default values
            /**
             * @brief Default indicator of short option
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            static constexpr const char *DEFAULT_INDICATOR_SHORT = "-";

            /**
             * @brief Default indicator of long option
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            static constexpr const char *DEFAULT_INDICATOR_LONG = "--";

            /**
             * @brief Default value delimiter
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            static constexpr const char *DEFAULT_VALUE_DELIM = "=";

            /**
             * @brief Default options end marker
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            static constexpr const char *DEFAULT_OPTS_END_MARKER = "--";

        //* Ctors and dtor
            /**
             * @brief Default constructor
             * @details Creates new instance of Unix option style
             *
             * @throw std::bad_alloc in case of memory allocation failure
             * @throw Exceptions from OptionStyle::OptionStyle(const std::string &, const std::string &)
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            UnixStyle();

            /**
             * @brief Copy constructor
             * @details Creates new instance of Unix option style as a copy of Other
             *
             * @param[in] Other Instance to copy
             *
             * @throw std::bad_alloc in case of memory allocation failure
             * @throw Exceptions from OptionStyle::OptionStyle(const OptionStyle &)
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            UnixStyle(const UnixStyle &Other);

            /**
             * @brief Move constructor
             * @details Creates new instance of Unix option style moving Other
             *
             * @param[in] Other Instance to move
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            UnixStyle(UnixStyle &&Other) noexcept;

            /**
             * @brief Destroies instance of Unix option style
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual ~UnixStyle() noexcept;

        //* Getters
            /**
             * @brief Get indicator of short option
             * @return Option indicator
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual const char *getIndicatorShort() const;

            /**
             * @brief Get indicator of long option
             * @return Option indicator
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual const char *getIndicatorLong() const;

        //* etc
            /**
             * @brief Checks if Arg is an option
             * @param[in] Arg Argument to be checked
             * @return true if Arg is an option, false if not
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual bool isArgOptional(const std::string &Arg) const override;

            bool isShortOption(const std::string &Arg) const;
            bool isLongOption(const std::string &Arg) const;

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
             * @throw Exceptions from OptionStyle::splitArg(const std::string &, std::string &, std::string &)
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual void splitArg(
                const std::string &Arg,
                std::string &Option,
                std::string &Value
            ) const override;

        private:
            using OptionStyle::getIndicator;
            using OptionStyle::setIndicator;
            using OptionStyle::setValueDelimiter;
            using OptionStyle::setOptsEndMarker;
        };
    }
}
