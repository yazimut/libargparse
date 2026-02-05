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
    namespace OptStyles {
        /**
         * @class UnixStyle
         * @brief Unix CLI option style
         * @details Contains definition and basic parameters of CLI option style
         * that is typical for Unix-like systems
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        ARGPARSE_API class UnixStyle: public OptionStyle {
        public:
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

        protected:
            using OptionStyle::setIndicator;
            using OptionStyle::setValueDelimiter;

        private:
            static const std::string mShortIndicator;   ///< Short option indicator
            static const std::string mLongIndicator;    ///< Long option indicator
            static const std::string mValueDelim;       ///< Value delimiter
        };
    }
}
