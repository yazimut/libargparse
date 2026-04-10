/**
 * @file IArgumentParser.hpp
 * @brief Declaration of CLI arguments parser
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026 \n
 * MIT License: this software may be freely used, modified,
 * and distributed, provided that this notice is retained.
 */
#pragma once
#include "../api.hpp"
#include "../args/IOption.hpp"

#include <memory>
#include <string>
#include <vector>
#include <stdexcept>



namespace argparse {
    /**
     * @class IArgumentParser
     * @brief Abstract CLI arguments parser
     * @details Contains methods for parsing CLI arguments
     *
     * @warning This is an abstract class. Don't create its instances directly!
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    class ARGPARSE_API IArgumentParser {
    public:
    //* Ctors and dtor
        /**
         * @brief Default constructor
         * @details Creates new instance
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        IArgumentParser();

        /**
         * @brief Destroies instance
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual ~IArgumentParser() noexcept = 0;

    //* etc
        /**
         * @brief Add CLI option to parser
         * @details Adds new CLI option to parser by moving instance to internal vector
         *
         * @param[in] Opt Option to add
         *
         * @throw std::invalid_argument if there is already the same option in internal vector
         * @throw inherited from std::vector<T>::push_back(T &&)
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual void addArgument(std::unique_ptr<args::IOption> &&Opt);

        /**
         * @brief Parses given CLI arguments
         *
         * @param[in] argc Arguments count
         * @param[in] argv Arguments vector
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual void parse(int argc, const char *argv[]) const = 0;

    protected:
        virtual bool isArgOption(const std::string &Arg) const = 0;

    private:
    //* Deleted methods
        /**
         * @brief Copy constructor
         * @details Creates new instance as a copy of Other
         * @param[in] Other Instance to copy
         * @warning Explicitly deleted method!
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        IArgumentParser(const IArgumentParser &Other) = delete;

        /**
         * @brief Move constructor
         * @details Creates new instance moving Other
         * @param[in] Other Instance to move
         * @warning Explicitly deleted method!
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        IArgumentParser(IArgumentParser &&Other) noexcept = delete;

        /**
         * @brief Copy assignment operator
         * @details Copies Right instance to current one
         * @param[in] Right Instance to copy
         * @returns Reference to current instance
         * @throw std::bad_alloc in case of memory allocation failure
         * @warning Explicitly deleted method!
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        IArgumentParser &operator = (const IArgumentParser &Right) = delete;

        /**
         * @brief Move assignment operator
         * @details Moves Right instance to current one
         * @param[in] Right Instance to move
         * @returns Reference to current instance
         * @warning Explicitly deleted method!
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        IArgumentParser &operator = (IArgumentParser &&Right) noexcept = delete;

    //* Variables
        std::vector<std::unique_ptr<args::IOption>> mOptions;      ///< List of CLI options
    };
}
