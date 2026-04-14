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

using namespace std;
using namespace argparse;
using namespace argparse::args;



IArgumentParser::IArgumentParser():
mOptions() {}

IArgumentParser::~IArgumentParser() noexcept {}

void IArgumentParser::addArgument(unique_ptr<IOption> Opt) {
    for (const auto &ExistingOpt : mOptions) {
        if (*Opt == *ExistingOpt)
            throw invalid_argument(""); // TODO: exception
    }
    mOptions.push_back(std::move(Opt));
}

void IArgumentParser::parse([[maybe_unused]] int argc, [[maybe_unused]] const char *argv[]) const {}

const vector<unique_ptr<IOption>> &IArgumentParser::getOptions() const {
    return mOptions;
}
