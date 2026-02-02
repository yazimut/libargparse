/**
 * @file NARGS.cpp
 * @brief Contains definition of NARGS functions
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#include <argparse/args/NARGS.hpp>

using namespace std;
using namespace argparse;



string argparse::to_string(uint32_t Value) {
    switch (Value) {
        case NARGS::NO_MORE:
            return "argparse::NARGS::NO_MORE";
        case NARGS::ZERO_OR_ONE:
            return "argparse::NARGS::ZERO_OR_ONE";
        case NARGS::ZERO_AND_MORE:
            return "argparse::NARGS::ZERO_AND_MORE";
        case NARGS::ONE_AND_MORE:
            return "argparse::NARGS::ONE_AND_MORE";
        default:
            return to_string(Value);
    }

    // gag
    return "argparse::NARGS::UNEXPECTED_BEHAIVOUR";
}
