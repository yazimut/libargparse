/**
 * @file ArgumentParser.cpp
 * @brief Definition of CLI arguments parser
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#include <argparse/ArgumentParser.hpp>
#include <argparse/helpers.hpp>

#include <list>
#include <utility>

using namespace std;
using namespace argparse;



ArgumentParser::ArgumentParser() {}

ArgumentParser::ArgumentParser(const ArgumentParser &Other) {
    selfCopy(Other);
}

ArgumentParser::ArgumentParser(ArgumentParser &&Other) noexcept {
    selfMove(move(Other));
}

ArgumentParser::~ArgumentParser() {}

void ArgumentParser::parse(int argc, const char *argv[]) {
    list<string> Args;      ///< Args list

    for (int i = 0; i < argc; ++i) {
        string Arg = argv[i];   ///< Whole argument

        if (!isArgOptional(Arg)) {
            // Positional argument
            Args.push_back(move(Arg));
            continue;
        }

        // Optional argument
        string Option = "";     ///< Option with a sign
        string Value = "";      ///< Value if provided
        size_t ValueDelimPos = Arg.find_first_of("=:");
        if (ValueDelimPos != string::npos) {
            // Option with a value
            Value = Arg.substr(ValueDelimPos + 1);
        }
        Option = Arg.substr(0, ValueDelimPos);
    }
}

bool ArgumentParser::isArgOptional(const string &Arg) const {
    if (Arg[0] == '-') {
        // Unix notation
        return true;
    }
    if (Arg[0] == '/') {
        // Microsoft Windows notation
        return true;
    }

    return false;
}

void ArgumentParser::splitOption(
    const string &Arg,
    string &Option,
    string &Value
) const {

}

void ArgumentParser::selfCopy(const ArgumentParser &Other) {}

void ArgumentParser::selfMove(ArgumentParser &&Other) noexcept {}
