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

using namespace std;
using namespace argparse;
using namespace argparse::args;



WindowsArgParser::WindowsArgParser():
IArgumentParser() {
    // TODO: добавить маркер конца опций как опциональный аргумент
}

WindowsArgParser::~WindowsArgParser() noexcept {}

void WindowsArgParser::parse(int argc, const char *argv[]) {
    bool IsOptsAllowed = true;
    const vector<unique_ptr<IOption>> &Opts = getOptionsList();

    for (int i = 0; i < argc; ++i) {
        string Arg = argv[i];

        if (IsOptsAllowed) {
            if (isArgOption(Arg)) {
                string OptName  = "";
                string OptValue = "";
                splitOption(Arg, OptName, OptValue);

                // Перебрать все опции, найти нужную,
                for (const unique_ptr<IOption> &OptPtr : Opts) {
                    IOption *Opt = OptPtr.get();
                    if (Opt->isMatch(OptName)) {
                        // MATCH
                    }
                }

                // обработать
            }
        }

        // Positional argument
    }
}

bool WindowsArgParser::isArgOption(const string &Arg) const {
    return Arg.length() > 1 && Arg[0] == '/';
}

bool WindowsArgParser::splitOption(
    const string &Arg,
    string &Name,
    string &Value
) const {
    /*
      At this moment Arg must be like this:
        * Arg.length > 1
        * Arg[0] == '/'
    */

    /*
      Assuming, that Arg[1] - exactly a part of (or a full) option name. This is the most frequent
      In other case Arg[1] == ':' - this is such a strange option name, that in most cases will throw an error.
      Value in such situatuion does not matter anyway
    */
    size_t ValDelimPos = Arg.find(':', 2);
    Value = ValDelimPos != string::npos ? Arg.substr(ValDelimPos + 1) : "";

    Name = Arg.substr(static_cast<size_t>(1), ValDelimPos - 1);

    return ValDelimPos != string::npos;
}
