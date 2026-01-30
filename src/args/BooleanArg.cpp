/**
 * @file BooleanArg.cpp
 * @brief Definition of boolean CLI argument
 *
 * @version 1.0.0
 * @authors Eugene Azimut
 * @copyright Copyright (c) Eugene Azimut, 2026
 */
#include <argparse/args/BooleanArg.hpp>
#include <argparse/helpers.hpp>

using namespace std;
using namespace argparse;



BooleanArg::BooleanArg(
    const string &Flags, const string &Help,
    uint32_t NArgs,
    bool IsRequired, bool IsDeprecated,
    bool StoreValue, bool DefaultValue):
IArgument(Flags, Help, NArgs, IsRequired, IsDeprecated),
mStoreValue(StoreValue), mDefaultValue(DefaultValue) {}

BooleanArg::BooleanArg(const BooleanArg &Other):
IArgument(Other) {
    selfCopy(Other);
}

BooleanArg::BooleanArg(BooleanArg &&Other) noexcept:
IArgument(move(Other)) {
    selfMove(move(Other));
}

BooleanArg::~BooleanArg() {}

BooleanArg &BooleanArg::operator = (const BooleanArg &Right) {
    if (this == &Right) return *this;

    *(static_cast<IArgument *>(this)) = Right;
    selfCopy(Right);
    return *this;
}

BooleanArg &BooleanArg::operator = (BooleanArg &&Right) noexcept {
    if (this == &Right) return *this;

    *(static_cast<IArgument *>(this)) = move(Right);
    selfMove(move(Right));
    return *this;
}

void BooleanArg::selfCopy(const BooleanArg &Other) {
    mStoreValue   = Other.mStoreValue;
    mDefaultValue = Other.mDefaultValue;
}

void BooleanArg::selfMove(BooleanArg &&Other) noexcept {
    mStoreValue   = exchange_basic(Other.mStoreValue, true);
    mDefaultValue = exchange_basic(Other.mDefaultValue, false);
}

bool BooleanArg::getValue() const {
    return mValue;
}

bool BooleanArg::getStoreValue() const {
    return mStoreValue;
}

void BooleanArg::setStoreValue(bool Value) {
    mStoreValue = Value;
}

bool BooleanArg::getDefaultValue() const {
    return mDefaultValue;
}

void BooleanArg::setDefaultValue(bool Value) {
    mDefaultValue = Value;
}
