/**
 * @file WindowsStyle.hpp
 * @brief Declaration of Windows CLI option style
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
         * @class WindowsStyle
         * @brief Windows CLI option style
         * @details Contains definition and basic parameters of CLI option style
         * that is typical for Microsoft Windows
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        ARGPARSE_API class WindowsStyle final: public OptionStyle {
        public:
        //* Ctors and dtor
            /**
             * @brief Default constructor
             * @details Creates new instance of Windows option style
             *
             * @throw std::bad_alloc in case of memory allocation failure
             * @throw Exceptions from OptionStyle::OptionStyle(const std::string &, const std::string &)
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            WindowsStyle();

            /**
             * @brief Copy constructor
             * @details Creates new instance of Windows option style as a copy of Other
             *
             * @param[in] Other Instance to copy
             *
             * @throw std::bad_alloc in case of memory allocation failure
             * @throw Exceptions from OptionStyle::OptionStyle(const OptionStyle &)
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            WindowsStyle(const WindowsStyle &Other);

            /**
             * @brief Move constructor
             * @details Creates new instance of Windows option style moving Other
             *
             * @param[in] Other Instance to move
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            WindowsStyle(WindowsStyle &&Other) noexcept;

            /**
             * @brief Destroies instance of Windows option style
             *
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            virtual ~WindowsStyle() noexcept;

        protected:
            using OptionStyle::setIndicator;
            using OptionStyle::setValueDelimiter;

        private:
            static const std::string mIndicator;     ///< Option indicator
            static const std::string mValueDelim;    ///< Value delimiter
        };
    }
}
