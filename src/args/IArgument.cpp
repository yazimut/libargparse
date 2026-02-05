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
using namespace argparse::args;



IArgument::IArgument(
    const string &Help,
    uint32_t NArgs,
    bool IsRequired, bool IsDeprecated):
mHelp(""),
mNArgs(NARGS::NO_MORE),
mIsRequired(false), mIsDeprecated(false) {
    setHelp(Help);
    setNArgs(NArgs);
    setRequired(IsRequired);
    setDeprecated(IsDeprecated);
}

IArgument::IArgument(const IArgument &Other) {
    selfCopy(Other);
}

IArgument::IArgument(IArgument &&Other) noexcept {
    selfMove(move(Other));
}

IArgument::~IArgument() noexcept {}

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
    mHelp  = Other.mHelp;
    mNArgs = Other.mNArgs;
    mIsRequired   = Other.mIsRequired;
    mIsDeprecated = Other.mIsDeprecated;
}

void IArgument::selfMove(IArgument &&Other) noexcept {
    mHelp  = move(Other.mHelp);
    mNArgs = exchange_basic(Other.mNArgs, NARGS::NO_MORE);
    mIsRequired   = exchange_basic(Other.mIsRequired, false);
    mIsDeprecated = exchange_basic(Other.mIsDeprecated, false);
}
