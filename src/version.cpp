/**
 * @file version.cpp
 * @author Eugene Azimut (y.azimut@mail.ru)
 * @brief Definition of library current version
 * @version 1.0.0
 * @date 2025-12-25
 *
 * @copyright Copyright (c) Eugene Azimut, 2025
 *
 */
#include <argparse/version.hpp>
#include <string>

using namespace std;
using namespace argparse;



uint32_t argparse::getVersionNumeric() {
    return ARGPARSE_VERSION;
}

const char *argparse::getVersionString() {
    static string Version = "";
    if (Version.size() == 0) {
        Version.reserve(MAX_ARGPARSE_VERSION_STRING_SIZE);
        Version += to_string(ARGPARSE_VERSION_MAJOR) + '.';
        Version += to_string(ARGPARSE_VERSION_MINOR) + '.';
        Version += to_string(ARGPARSE_VERSION_PATCH);
    }
    return Version.c_str();
}
