/**
 * @file IOption.cpp
 * @brief Definition of abstract optional CLI argument
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026 \n
 * MIT License: this software may be freely used, modified,
 * and distributed, provided that this notice is retained.
 */
#include <argparse/args/IOption.hpp>
#include "../helpers.hpp"

using namespace std;
using namespace argparse;
using namespace argparse::args;



IOption::IOption(
    const Flags &FlagsList,
    const string &Help,
    int NArgs,
    bool IsRequired, bool IsDeprecated):
IArgument(Help, NArgs, IsDeprecated),
mIsRequired(false), mFlags() {
    setRequired(IsRequired);
    setFlags(FlagsList);
}

IOption::IOption(
    Flags &&FlagsList,
    const string &Help,
    int NArgs,
    bool IsRequired, bool IsDeprecated):
IArgument(Help, NArgs, IsDeprecated),
mIsRequired(false), mFlags() {
    setRequired(IsRequired);
    setFlags(move(FlagsList));
}

IOption::IOption(const IOption &Other):
IArgument(Other),
mIsRequired(false), mFlags() {
    selfCopy(Other);
}

IOption::IOption(IOption &&Other) noexcept:
IArgument(move(Other)),
mIsRequired(false), mFlags() {
    selfMove(move(Other));
}

IOption::~IOption() noexcept {}

IOption &IOption::operator = (const IOption &Right) {
    if (this == &Right) return *this;

    IArgument::operator=(Right);
    selfCopy(Right);

    return *this;
}

IOption &IOption::operator = (IOption &&Right) noexcept {
    if (this == &Right) return *this;

    IArgument::operator=(move(Right));
    selfMove(move(Right));

    return *this;
}

bool IOption::operator == (const IOption &Right) const {
    return isEquals(Right);
}

bool IOption::operator != (const IOption &Right) const {
    return !isEquals(Right);
}

bool IOption::isRequired() const {
    return mIsRequired;
}

void IOption::setRequired(bool IsRequired) {
    mIsRequired = IsRequired;
}

const Flags &IOption::getFlags() const {
    return mFlags;
}

void IOption::setFlags(const Flags &FlagsList) {
    mFlags = FlagsList;
}

void IOption::setFlags(Flags &&FlagsList) {
    mFlags = move(FlagsList);
}

bool IOption::isEquals(const IOption &Other) const {
    for (const string &ThisFlag : mFlags) {
        for (const string &OtherFlag : Other.mFlags) {
            if (ThisFlag == OtherFlag) return true;
        }
    }
    return false;
}

bool IOption::isMatch(const string &Opt) const {
    for (const string &Flag : mFlags) {
        if (Opt == Flag) return true;
    }
    return false;
}

void IOption::selfCopy(const IOption &Other) {
    mIsRequired = Other.mIsRequired;
    mFlags      = Other.mFlags;
}

void IOption::selfMove(IOption &&Other) noexcept {
    mIsRequired = exchange_basic<bool>(Other.mIsRequired, false);
    mFlags      = move(Other.mFlags);
}
