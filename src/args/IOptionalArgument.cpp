/**
 * @file IOptionalArgument.cpp
 * @brief Definition of abstract optional CLI argument
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#include <argparse/args/IOptionalArgument.hpp>
#include "argparse/helpers.hpp"

using namespace std;
using namespace argparse;



IOptionalArgument::IOptionalArgument(
    const Flags &FlagsList,
    const string &Help,
    uint32_t NArgs,
    bool IsRequired, bool IsDeprecated):
IArgument(Help, NArgs, IsRequired, IsDeprecated),
mFlags() {
    setFlags(FlagsList);
}

IOptionalArgument::IOptionalArgument(
    Flags &&FlagsList,
    const string &Help,
    uint32_t NArgs,
    bool IsRequired, bool IsDeprecated):
IArgument(Help, NArgs, IsRequired, IsDeprecated),
mFlags() {
    setFlags(move(FlagsList));
}

IOptionalArgument::IOptionalArgument(const IOptionalArgument &Other):
IArgument(Other) {
    selfCopy(Other);
}

IOptionalArgument::IOptionalArgument(IOptionalArgument &&Other) noexcept:
IArgument(move(Other)) {
    selfMove(move(Other));
}

IOptionalArgument::~IOptionalArgument() {}

IOptionalArgument &IOptionalArgument::operator = (const IOptionalArgument &Right) {
    if (this == &Right) return *this;

    *(static_cast<IArgument *>(this)) = Right;
    selfCopy(Right);
    return *this;
}

IOptionalArgument &IOptionalArgument::operator = (IOptionalArgument &&Right) noexcept {
    if (this == &Right) return *this;

    *(static_cast<IArgument *>(this)) = move(Right);
    selfMove(move(Right));
    return *this;
}

const Flags &IOptionalArgument::getFlags() const {
    return mFlags;
}

void IOptionalArgument::setFlags(const Flags &FlagsList) {
    mFlags = FlagsList;
}

void IOptionalArgument::setFlags(Flags &&FlagsList) {
    mFlags = move(FlagsList);
}

void IOptionalArgument::selfCopy(const IOptionalArgument &Other) {
    mFlags = Other.mFlags;
}

void IOptionalArgument::selfMove(IOptionalArgument &&Other) noexcept {
    mFlags = move(Other.mFlags);
}
