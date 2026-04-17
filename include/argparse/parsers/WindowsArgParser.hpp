/**
 * @file WindowsArgParser.hpp
 * @brief Declaration of Windows-style CLI arguments parser
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026 \n
 * MIT License: this software may be freely used, modified,
 * and distributed, provided that this notice is retained.
 */
#pragma once
#include "../api.hpp"
#include "IArgumentParser.hpp"

#include <string>



namespace argparse {
    /**
     * @class WindowsArgParser
     * @brief Windows-style CLI arguments parser
     * @details Contains methods for parsing CLI arguments
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    class ARGPARSE_API WindowsArgParser: public IArgumentParser {
    public:
    //* Ctors and dtor
        /**
         * @brief Default constructor
         * @details Creates new instance
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        WindowsArgParser();

        /**
         * @brief Destroies instance
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual ~WindowsArgParser() noexcept override;

    //* etc
        /**
         * @brief Parses given CLI arguments
         *
         * @param[in] argc Arguments count
         * @param[in] argv Arguments vector
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual void parse(int argc, const char *argv[]) override;

    protected:
        /**
         * @brief Is given CLI argument an option?
         *
         * @param[in] Arg Argument to check
         * @returns true or false
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual bool isArgOption(const std::string &Arg) const;

        /**
         * @brief Split given CLI option into a name and value
         *
         * @param[in] Opt Option to split
         * @param[out] Name Extracted option name
         * @param[out] Value Extracted option value
         * @returns true if value has been extracted (even if it's empty), false if not
         *
         * @note In some cases (e.g. "/:" or "/:sometext")
         * this method can return an empty string as an option name
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual bool splitOption(
            const std::string &Opt,
            std::string &Name,
            std::string &Value
        ) const;

    private:
        /**
         * @brief Copy constructor
         * @details Creates new instance as a copy of Other
         * @param[in] Other Instance to copy
         * @warning Explicitly deleted method!
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        WindowsArgParser(const WindowsArgParser &Other) = delete;

        /**
         * @brief Move constructor
         * @details Creates new instance moving Other
         * @param[in, out] Other Instance to move
         * @warning Explicitly deleted method!
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        WindowsArgParser(WindowsArgParser &&Other) noexcept = delete;

        /**
         * @brief Copy assignment operator
         * @details Copies Right instance to current one
         * @param[in] Right Instance to copy
         * @returns Reference to current instance
         * @warning Explicitly deleted method!
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        WindowsArgParser &operator = (const WindowsArgParser &Right) = delete;

        /**
         * @brief Move assignment operator
         * @details Moves Right instance to current one
         * @param[in, out] Right Instance to move
         * @returns Reference to current instance
         * @warning Explicitly deleted method!
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        WindowsArgParser &operator = (WindowsArgParser &&Right) noexcept = delete;

    //* Variables
    };
}
