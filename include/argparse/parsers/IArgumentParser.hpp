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
         * @brief Will parser find and handle CLI options?
         * @returns true or false
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        inline bool isOptionsAllowed() const {
            return mIsOptionsAllowed;
        }

        /**
         * @brief Allowes parser to find and handle CLI options
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        inline void allowOptions() {
            mIsOptionsAllowed = true;
        }

        /**
         * @brief Disallowes parser to find and handle CLI options
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        inline void disallowOptions() {
            mIsOptionsAllowed = false;
        }

        /**
         * @brief Add CLI option to parser
         *
         * @param[in] Opt Option to add
         *
         * @throw std::invalid_argument if there is already the same option
         * @throw inherited from std::vector<T>::push_back(T &&)
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual void addArgument(std::unique_ptr<args::IOption> Opt);

        /**
         * @brief Parse given CLI arguments
         *
         * @param[in] argc Arguments count
         * @param[in] argv Arguments vector
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        virtual void parse(int argc, const char *argv[]) = 0;

    protected:
        /**
         * @brief Get defined CLI options list
         * @returns Reference to the list of defined options
         *
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        inline const std::vector<std::unique_ptr<args::IOption>> &getOptionsList() const {
            return mOptions;
        }

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
         * @param[in, out] Other Instance to move
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
         * @param[in, out] Right Instance to move
         * @returns Reference to current instance
         * @warning Explicitly deleted method!
         * @version 1.0.0
         * @authors Eugene Azimut
         */
        IArgumentParser &operator = (IArgumentParser &&Right) noexcept = delete;

    //* Variables
        bool mIsOptionsAllowed;                                 ///< Will parser find and handle CLI options
        std::vector<std::unique_ptr<args::IOption>> mOptions;   ///< List of CLI options
    };
}
