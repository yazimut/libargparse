/**
 * @file IArgumentParser.cpp
 * @brief Definition of CLI arguments parser
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026 \n
 * MIT License: this software may be freely used, modified,
 * and distributed, provided that this notice is retained.
 */
#include <argparse/parsers/IArgumentParser.hpp>
#include "../helpers.hpp"

#include <utility>

using namespace std;
using namespace argparse;



IArgumentParser::IArgumentParser() {}

IArgumentParser::IArgumentParser(const IArgumentParser &Other) {
    selfCopy(Other);
}

IArgumentParser::IArgumentParser(IArgumentParser &&Other) noexcept {
    selfMove(move(Other));
}

IArgumentParser::~IArgumentParser() noexcept {}

IArgumentParser &IArgumentParser::operator = (const IArgumentParser &Right) {
    if (this != &Right) selfCopy(Right);
    return *this;
}

IArgumentParser &IArgumentParser::operator = (IArgumentParser &&Right) noexcept {
    if (this != &Right) selfMove(move(Right));
    return *this;
}

void IArgumentParser::parse([[maybe_unused]] int argc, [[maybe_unused]] const char *argv[]) const {}

void IArgumentParser::selfCopy([[maybe_unused]] const IArgumentParser &Other) {}

void IArgumentParser::selfMove([[maybe_unused]] IArgumentParser &&Other) noexcept {}
