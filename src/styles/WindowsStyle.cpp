/**
 * @file WindowsStyle.cpp
 * @brief Definition of Windows CLI option style
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#include <argparse/styles/WindowsStyle.hpp>

using namespace std;
using namespace argparse;
using namespace argparse::styles;



WindowsStyle::WindowsStyle():
OptionStyle(DEFAULT_INDICATOR, DEFAULT_VALUE_DELIM, DEFAULT_OPTS_END_MARKER) {}

WindowsStyle::WindowsStyle(const WindowsStyle &Other):
OptionStyle(Other) {}

WindowsStyle::WindowsStyle(WindowsStyle &&Other) noexcept:
OptionStyle(move(Other)) {}

WindowsStyle::~WindowsStyle() noexcept {}
