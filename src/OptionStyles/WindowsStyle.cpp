/**
 * @file WindowsStyle.cpp
 * @brief Definition of basic CLI option Windows style
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#include <argparse/OptionStyles/WindowsStyle.hpp>

using namespace std;
using namespace argparse;
using namespace argparse::OptStyles;



WindowsStyle::WindowsStyle():
OptionStyle("/", ":") {}

WindowsStyle::WindowsStyle(const WindowsStyle &Other):
OptionStyle(Other) {}

WindowsStyle::WindowsStyle(WindowsStyle &&Other) noexcept:
OptionStyle(move(Other)) {}

WindowsStyle::~WindowsStyle() noexcept {}
