/**
 * @file UnixStyle.cpp
 * @brief Definition of Unix CLI option style
 *
 * @details This style differs from basic OptionStyle.
 * In order to improve performance, instead of reusing code,
 * a new one was written, specific to the current style.
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#include <argparse/styles/UnixStyle.hpp>

using namespace std;
using namespace argparse;
using namespace argparse::styles;



UnixStyle::UnixStyle():
OptionStyle("", DEFAULT_VALUE_DELIM, DEFAULT_OPTS_END_MARKER) {}

UnixStyle::UnixStyle(const UnixStyle &Other):
OptionStyle(Other) {}

UnixStyle::UnixStyle(UnixStyle &&Other) noexcept:
OptionStyle(move(Other)) {}

UnixStyle::~UnixStyle() noexcept {}

bool UnixStyle::isArgOptional(const string &Arg) const {
    // Is long?
    if (Arg.length() > 2) {
        for (size_t i = 0; i < 2; ++i) {
            if (Arg[i] != '-') break;
        }
    }


    if (Arg.empty()) return false;

    if (Arg[0] == '-') {
        // Arg is at least a short option
        return true;
    }

    return false;
}

bool UnixStyle::isShortOption(const string &Arg) const {
    if (Arg.length() <= 1) return false;
    if (Arg[0] != '-') return false;

    if (
        Arg.length() > 1 &&
        Arg[0] == '-'
    )
}

bool UnixStyle::isLongOption(const string &Arg) const {
    string Indicator = DEFAULT_INDICATOR_LONG;
    if (Arg.length() <= Indicator.length()) return false;

    for (size_t i = 0; i < Indicator.length(); ++i)
        if (Arg[i] != Indicator[i]) return false;

    return true;
}

void UnixStyle::splitArg(const string &Arg, string &Option, string &Value) const {
    if (!isArgOptional(Arg)) {
        // TODO: throw ArgparseError("not an optional")
        throw runtime_error("Not an optional 0");
    }

    string Opt = "";
    string Val = "";

    if (Arg.substr(0, mLongIndicator.length()) == mLongIndicator) {
        //* Long option
        if (Arg.length() == 2) {
            // Arg == "--"
            // TODO: throw ArgparseError("Invalid option (option not provided)")
            throw runtime_error("Invalid option (option not provided) 1");
        }

        size_t DelimPos = Arg.find(mValueDelim);

        // Extract value
        if (DelimPos != string::npos) {
            //* Value should have been provided
            // Maybe empty
            Val = move(Arg.substr(DelimPos + mValueDelim.length()));
        }

        // Extract option
        Opt = move(Arg.substr(mLongIndicator.length(), DelimPos - mLongIndicator.length()));
        if (Opt.empty()) {
            // It seems Arg == "--=*"
            if (Val.empty()) {
                // It seems Arg == "--="
                // TODO: throw ArgparseError("Value delimiter (\"=\") cannot be an option")
                throw runtime_error("Value delimiter (\"=\") cannot be an option 3");
            } else {
                // It seems Arg == "--=+"
                // TODO: throw ArgparseError("Invalid option (option not provided)")
                throw runtime_error("Invalid option (option not provided) 4");
            }
        }
    } else {
        //* Short option
        // Extract option
        if (Arg.length() == 1) {
            // Arg == "-"
            // TODO: throw ArgparseError("Invalid option (option not provided)")
            throw runtime_error("Invalid option (option not provided) 5");
        }

        Opt = Arg[1];
        if (Opt == mValueDelim) {
            // Arg == "-=*"
            // TODO: throw ArgparseError("Value delimiter (\"=\") cannot be an option")
            throw runtime_error("Value delimiter (\"=\") cannot be an option 6");
        }

        // Extract value
        size_t DelimPos = Arg.find(mValueDelim, 2);
        if (DelimPos == 2) {
            // It seems Arg == "-f=*"
            // TODO: throw ArgparseError("UnixStyle doesn't support value delimiters in short options")
            throw runtime_error("UnixStyle doesn't support value delimiters in short options 7");
        }

        Val = move(Arg.substr(2));
    }

    Option = move(Opt);
    Value  = move(Val);
}
