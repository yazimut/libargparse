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
    namespace styles {
        /**
         * @class WindowsStyle
         * @brief Windows CLI option style
         * @details Contains definition and basic parameters of CLI option style
         * that is typical for Microsoft Windows
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        class ARGPARSE_API WindowsStyle final: public OptionStyle {
        public:
        //* Default values
            /**
             * @brief Default indicator
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            static constexpr const char *DEFAULT_INDICATOR = "/";

            /**
             * @brief Default value delimiter
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            static constexpr const char *DEFAULT_VALUE_DELIM = ":";

            /**
             * @brief Default options end marker
             * @version 1.0.0
             * @authors Eugene Azimut
             */
            static constexpr const char *DEFAULT_OPTS_END_MARKER = "--";

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

        private:
            using OptionStyle::setIndicator;
            using OptionStyle::setValueDelimiter;
            using OptionStyle::setOptsEndMarker;
        };
    }
}
