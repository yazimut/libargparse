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
    bool &Output,
    const Flags &Flags, const string &Help,
    uint32_t NArgs,
    bool IsRequired, bool IsDeprecated,
    bool StoreValue, bool DefaultValue):
IOptionalArgument(Flags, Help, NArgs, IsRequired, IsDeprecated),
mOutput(&Output),
mStoreValue(StoreValue), mDefaultValue(DefaultValue) {
    setNArgs(NArgs);
    setStoreValue(StoreValue);
    setDefaultValue(DefaultValue);
}

BooleanArg::BooleanArg(
    bool &Output,
    Flags &&Flags, const string &Help,
    uint32_t NArgs,
    bool IsRequired, bool IsDeprecated,
    bool StoreValue, bool DefaultValue):
IOptionalArgument(move(Flags), Help, NArgs, IsRequired, IsDeprecated),
mOutput(&Output),
mStoreValue(StoreValue), mDefaultValue(DefaultValue) {
    setNArgs(NArgs);
    setStoreValue(StoreValue);
    setDefaultValue(DefaultValue);
}

BooleanArg::BooleanArg(const BooleanArg &Other):
IOptionalArgument(Other) {
    selfCopy(Other);
}

BooleanArg::BooleanArg(BooleanArg &&Other) noexcept:
IOptionalArgument(move(Other)) {
    selfMove(move(Other));
}

BooleanArg::~BooleanArg() {
    mOutput = nullptr;
}

void BooleanArg::setNArgs(uint32_t NArgs) {
    if (
        NArgs == 0 ||
        NArgs == 1 ||
        NArgs == NARGS::NO_MORE ||
        NArgs == NARGS::ZERO_OR_ONE
    ) {
        IOptionalArgument::setNArgs(NArgs);
    } else {
        throw invalid_argument(
            string("argparse::BooleanArg::setNArgs(uint32_t): invalid NARgs value - ") +
            to_string(NArgs)
        );
    }
}

bool *BooleanArg::getOutput() const {
    return mOutput;
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

void BooleanArg::selfCopy(const BooleanArg &Other) {
    mOutput       = Other.mOutput;
    mStoreValue   = Other.mStoreValue;
    mDefaultValue = Other.mDefaultValue;
}

void BooleanArg::selfMove(BooleanArg &&Other) noexcept {
    mOutput       = exchange_basic(Other.mOutput, nullptr);
    mStoreValue   = exchange_basic(Other.mStoreValue, true);
    mDefaultValue = exchange_basic(Other.mDefaultValue, false);
}
