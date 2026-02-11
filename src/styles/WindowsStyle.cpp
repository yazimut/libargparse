/**
 * @file WindowsStyle.cpp
 * @brief Definition of basic CLI option Windows style
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#include <argparse/styles/WindowsStyle.hpp>

using namespace std;
using namespace argparse;
using namespace argparse::styles;



const string WindowsStyle::mIndicator  = "/";
const string WindowsStyle::mValueDelim = ":";



WindowsStyle::WindowsStyle():
OptionStyle(mIndicator, mValueDelim) {}

WindowsStyle::WindowsStyle(const WindowsStyle &Other):
OptionStyle(Other) {}

WindowsStyle::WindowsStyle(WindowsStyle &&Other) noexcept:
OptionStyle(move(Other)) {}

WindowsStyle::~WindowsStyle() noexcept {}
