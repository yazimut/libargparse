/**
 * @file argparse.hpp
 * @brief Single-include header for library
 * @details Use this header to include all basic functionality of libargparse
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026 \n
 * MIT License: this software may be freely used, modified,
 * and distributed, provided that this notice is retained.
 */
#pragma once
#include "api.hpp"

#if defined(_WIN32)
    #include "parsers/WindowsArgParser.hpp"
    //#include "parsers/PowershellArgParser.hpp"
#else
    //#include "parsers/POSIXArgParser.hpp"
    //#include "parsers/GNUArgParser.hpp"
    //#include "parsers/UNIXArgParser.hpp"
#endif
