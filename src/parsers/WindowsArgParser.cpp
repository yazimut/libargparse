/**
 * @file WindowsArgParser.cpp
 * @brief Definition of CLI arguments parser
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026 \n
 * MIT License: this software may be freely used, modified,
 * and distributed, provided that this notice is retained.
 */
#include <argparse/parsers/WindowsArgParser.hpp>
#include "../helpers.hpp"

#include <string>
#include <utility>
#include <iostream>

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

void WindowsArgParser::parse(int argc, const char *argv[]) const {
    bool IsOptsAllowed = true;

    for (int i = 0; i < argc; ++i) {
        printf("argv[%d] \"%s\": ", i, argv[i]);
        string arg = argv[i];

        if (IsOptsAllowed) {
            // End of options?
            if (arg == "--" || arg == "/-") {
                IsOptsAllowed = false;
                printf("no more options\n");
                continue;
            }

            // Option?
            if (arg[0] == '/' && arg.length() > 1) {
                // Option
                printf("option\n");
                continue;
            }
        }

        // Positional argument
        printf("positional argument\n");
    }
}

void WindowsArgParser::selfCopy([[maybe_unused]] const WindowsArgParser &Other) {}

void WindowsArgParser::selfMove([[maybe_unused]] WindowsArgParser &&Other) noexcept {}
