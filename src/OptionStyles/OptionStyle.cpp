/**
 * @file OptionStyle.cpp
 * @brief Definition of basic CLI option style
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#include <argparse/OptionStyles/OptionStyle.hpp>

using namespace std;
using namespace argparse;
using namespace argparse::OptStyles;



OptionStyle::OptionStyle(const string &Indicator, const string &ValueDelim):
mIndicator(""), mValueDelim("") {
    setIndicator(Indicator);
    setValueDelimiter(ValueDelim);
}

OptionStyle::OptionStyle(const OptionStyle &Other):
mIndicator(Other.mIndicator), mValueDelim(Other.mValueDelim) {}

OptionStyle::OptionStyle(OptionStyle &&Other) noexcept:
mIndicator(move(Other.mIndicator)), mValueDelim(move(Other.mValueDelim)) {}

OptionStyle::~OptionStyle() noexcept {}

const char *OptionStyle::getIndicator() const {
    return mIndicator.c_str();
}

void OptionStyle::setIndicator(const string &Value) {
    if (Value.empty())
        throw invalid_argument("OptionStyle::setIndicator(const string &): Indicator cannot be empty string");

    mIndicator = Value;
}

const char *OptionStyle::getValueDelimiter() const {
    return mValueDelim.c_str();
}

void OptionStyle::setValueDelimiter(const string &Value) {
    mValueDelim = Value;
}

bool OptionStyle::isArgOptional(const string &Arg) const {
    if (Arg.length() <= mIndicator.length()) return false;

    for (size_t i = 0; i < mIndicator.length(); ++i)
        if (Arg[i] != mIndicator[i]) return false;

    return true;
}

void OptionStyle::splitArg(const string &Arg, string &Option, string &Value) const {
    if (!isArgOptional(Arg)) {
        // TODO: throw ArgparseError("not an optional")
        throw runtime_error("Not an optional");
    }

    size_t DelimPos = Arg.find(mValueDelim);
    /*
       std::string::find(const std::string &__str) returns 0
       if __str is an empty string, which means
       value cannot be provided in this Style.
       So the whole string is an option
    */
    if (DelimPos == 0) DelimPos = string::npos;

    // Extract option
    string Opt = Arg.substr(mIndicator.length(), DelimPos - mIndicator.length());
    if (Option.empty()) {
        /*
           Option wasn't provided!
           Examples:
            * "-"           mValueDelim doesn't matter
            * "-="          in case of mValueDelim == "="
            * "-=Value"     in case of mValueDelim == "="
           TODO: throw ArgparseError("option wasn't provided")
        */
       throw runtime_error("Option wasn't provided");
    }

    // Extract value if provided
    string Val = "";
    if (DelimPos != string::npos) {
        // Value is provided
        Val = move(Arg.substr(DelimPos + mValueDelim.length()));
    }

    // Return
    Option = move(Opt);
    Value  = move(Val);
}
