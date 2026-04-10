/**
 * @file IArgument.cpp
 * @brief Definition of abstract CLI argument
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026 \n
 * MIT License: this software may be freely used, modified,
 * and distributed, provided that this notice is retained.
 */
#include <argparse/args/IArgument.hpp>
#include "../helpers.hpp"

using namespace std;
using namespace argparse;
using namespace argparse::args;



IArgument::IArgument(
    const string &Help,
    int NArgs,
    bool IsDeprecated):
mHelp(""),
mNArgs(NARGS::NO_MORE),
mIsDeprecated(false) {
    setHelp(Help);
    setNArgs(NArgs);
    setDeprecated(IsDeprecated);
}

IArgument::IArgument(const IArgument &Other):
mHelp(""),
mNArgs(NARGS::NO_MORE),
mIsDeprecated(false) {
    selfCopy(Other);
}

IArgument::IArgument(IArgument &&Other) noexcept:
mHelp(""),
mNArgs(NARGS::NO_MORE),
mIsDeprecated(false) {
    selfMove(move(Other));
}

IArgument::~IArgument() noexcept {}

IArgument &IArgument::operator = (const IArgument &Right) {
    if (this != &Right) selfCopy(Right);
    return *this;
}

IArgument &IArgument::operator = (IArgument &&Right) {
    if (this != &Right) selfMove(move(Right));
    return *this;
}

const char *IArgument::getHelp() const {
    return mHelp.c_str();
}

void IArgument::setHelp(const string &Help) {
    mHelp = Help;
}

int IArgument::getNArgs() const {
    return mNArgs;
}

void IArgument::setNArgs(int NArgs) {
    if (NArgs < NARGS::ONE_AND_MORE)
        throw invalid_argument("NArgs cannot be negative");
    mNArgs = NArgs;
}

bool IArgument::isDeprecated() const {
    return mIsDeprecated;
}

void IArgument::setDeprecated(bool IsDeprecated) {
    mIsDeprecated = IsDeprecated;
}

void IArgument::selfCopy(const IArgument &Other) {
    mHelp  = Other.mHelp;
    mNArgs = Other.mNArgs;
    mIsDeprecated = Other.mIsDeprecated;
}

void IArgument::selfMove(IArgument &&Other) noexcept {
    mHelp  = move(Other.mHelp);
    mNArgs = exchange_basic(Other.mNArgs, NARGS::NO_MORE);
    mIsDeprecated = exchange_basic(Other.mIsDeprecated, false);
}
