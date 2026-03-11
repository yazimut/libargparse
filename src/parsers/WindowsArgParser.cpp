/**
 * @file WindowsArgParser.cpp
 * @brief Definition of CLI arguments parser
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#include <argparse/parsers/WindowsArgParser.hpp>
#include "../helpers.hpp"

#include <utility>

using namespace std;
using namespace argparse;



WindowsArgParser::WindowsArgParser():
IArgumentParser() {}

WindowsArgParser::WindowsArgParser(const WindowsArgParser &Other):
IArgumentParser(Other) {
    selfCopy(Other);
}

WindowsArgParser::WindowsArgParser(WindowsArgParser &&Other) noexcept:
IArgumentParser(move(Other)) {
    selfMove(move(Other));
}

WindowsArgParser::~WindowsArgParser() noexcept {}

WindowsArgParser &WindowsArgParser::operator = (const WindowsArgParser &Right) {
    if (this != &Right) {
        IArgumentParser::operator=(Right);
        selfCopy(Right);
    }

    return *this;
}

WindowsArgParser &WindowsArgParser::operator = (WindowsArgParser &&Right) noexcept {
    if (this != &Right) {
        IArgumentParser::operator=(move(Right));
        selfMove(move(Right));
    }

    return *this;
}

void WindowsArgParser::parse([[maybe_unused]] int argc, [[maybe_unused]] const char *argv[]) const {}

void WindowsArgParser::selfCopy([[maybe_unused]] const WindowsArgParser &Other) {}

void WindowsArgParser::selfMove([[maybe_unused]] WindowsArgParser &&Other) noexcept {}
