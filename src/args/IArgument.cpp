/**
 * @file IArgument.cpp
 * @brief Definition of abstract CLI argument
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#include <argparse/args/IArgument.hpp>
#include "argparse/helpers.hpp"

using namespace std;
using namespace argparse;



IArgument::IArgument(
    const string &Flags, const string &Help,
    uint32_t NArgs,
    bool IsRequired, bool IsDeprecated):
mFlags(Flags), mHelp(Help),
mNArgs(NArgs),
mIsRequired(IsRequired), mIsDeprecated(IsDeprecated) {}

IArgument::IArgument(const IArgument &Other) {
    selfCopy(Other);
}

IArgument::IArgument(IArgument &&Other) noexcept {
    selfMove(move(Other));
}

IArgument::~IArgument() {}

IArgument &IArgument::operator = (const IArgument &Right) {
    if (this == &Right) return *this;
    selfCopy(Right);
    return *this;
}

IArgument &IArgument::operator = (IArgument &&Right) noexcept {
    if (this == &Right) return *this;
    selfMove(move(Right));
    return *this;
}

const char *IArgument::getFlags() const {
    return mFlags.c_str();
}

const char *IArgument::getHelp() const {
    return mHelp.c_str();
}

void IArgument::setHelp(const string &Help) {
    mHelp = Help;
}

uint32_t IArgument::getNArgs() const {
    return mNArgs;
}

void IArgument::setNArgs(uint32_t NArgs) {
    mNArgs = NArgs;
}

bool IArgument::isRequired() const {
    return mIsRequired;
}

void IArgument::setRequired(bool IsRequired) {
    mIsRequired = IsRequired;
}

bool IArgument::isDeprecated() const {
    return mIsDeprecated;
}

void IArgument::setDeprecated(bool IsDeprecated) {
    mIsDeprecated = IsDeprecated;
}

void IArgument::selfCopy(const IArgument &Other) {
    mFlags = Other.mFlags;
    mHelp  = Other.mHelp;
    mNArgs = Other.mNArgs;
    mIsRequired   = Other.mIsRequired;
    mIsDeprecated = Other.mIsDeprecated;
}

void IArgument::selfMove(IArgument &&Other) noexcept {
    mFlags = move(Other.mFlags);
    mHelp  = move(Other.mHelp);
    mNArgs = exchange_basic(Other.mNArgs, NARGS::NO_MORE);
    mIsRequired   = exchange_basic(Other.mIsRequired, false);
    mIsDeprecated = exchange_basic(Other.mIsDeprecated, false);
}
