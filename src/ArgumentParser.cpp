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

ArgumentParser::~ArgumentParser() noexcept {}

void ArgumentParser::parse(int argc, const char *argv[]) {
    list<string> Args;          ///< Args list

    for (int i = 0; i < argc; ++i) {
        string Arg = argv[i];   ///< Whole argument

        if (Arg[0] == '-') {
            // Optional argument
            if (Arg[1] == '-') {
                //* Long option

            } else {
                //* Short option
            }

        } else {
            // Positional argument
        }
    }
}

void ArgumentParser::splitOption(
    const string &Arg,
    string &Option,
    string &Value
) const {
    size_t ValueDelimPos = Arg.find_first_of("=:");
    if (ValueDelimPos != string::npos) {
        Value = Arg.substr(ValueDelimPos + 1);
    }
    Option = Arg.substr(0, ValueDelimPos);
}

void ArgumentParser::selfCopy(const ArgumentParser &Other) {}

void ArgumentParser::selfMove(ArgumentParser &&Other) noexcept {}
