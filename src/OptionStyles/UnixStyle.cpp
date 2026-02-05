/**
 * @file UnixStyle.cpp
 * @brief Definition of basic CLI option Windows style
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#include <argparse/OptionStyles/UnixStyle.hpp>

using namespace std;
using namespace argparse;
using namespace argparse::OptStyles;



const string UnixStyle::mShortIndicator = "-";
const string UnixStyle::mLongIndicator  = "--";
const string UnixStyle::mValueDelim     = "=";



UnixStyle::UnixStyle():
OptionStyle(mLongIndicator, mValueDelim) {}

UnixStyle::UnixStyle(const UnixStyle &Other):
OptionStyle(Other) {}

UnixStyle::UnixStyle(UnixStyle &&Other) noexcept:
OptionStyle(move(Other)) {}

UnixStyle::~UnixStyle() noexcept {}

bool UnixStyle::isArgOptional(const string &Arg) const {
    if (OptionStyle::isArgOptional(Arg))
        // Arg is a long option
        return true;

    if (Arg.length() <= mShortIndicator.length()) return false;

    for (size_t i = 0; i < mShortIndicator.length(); ++i)
        if (Arg[i] != mShortIndicator[i]) return false;

    return true;
}

void UnixStyle::splitArg(const string &Arg, string &Option, string &Value) const {
    if (Arg.substr(0, mLongIndicator.length()) == mLongIndicator) {
        // Long option
        OptionStyle::splitArg(Arg, Option, Value);
    } else {
        // Short option
        if (!isArgOptional(Arg)) {
            // TODO: throw ArgparseError("not an optional")
            throw runtime_error("Not an optional");
        }

        /*
           Extract option
           It could be only one symbol!
           At the same time, Arg != "-"
        */
        string Opt = Arg.substr(mShortIndicator.length(), 1);

        // Extract value
        string Val = Arg.substr(mShortIndicator.length() + 1);

        Option = move(Opt);
        Value  = move(Val);
    }
}
