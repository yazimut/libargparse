/**
 * @file StringArg.cpp
 * @brief Definition of abstract CLI argument
 *
 * @version 1.0.0
 * @date 2026-01-28
 * @authors Eugene Azimut (y.azimut@mail.ru)
 * @copyright Copyright (c) Eugene Azimut, 2026
 *
 */
#include <argparse/args/StringArg.hpp>

using namespace std;
using namespace argparse;



BooleanArg::BooleanArg(
    const string &Flags, const string &Help,
    bool IsRequired, bool IsDeprecated):
IArgument(Flags, Help, IsRequired, IsDeprecated) {}

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

    *static_cast<IArgument *>(this) = Right;
    selfCopy(Right);
    return *this;
}

BooleanArg &BooleanArg::operator = (BooleanArg &&Right) noexcept {
    if (this == &Right) return *this;

    *static_cast<IArgument *>(this) = move(Right);
    selfMove(move(Right));
    return *this;
}

void BooleanArg::selfCopy(const BooleanArg &Other) {}

void BooleanArg::selfMove(BooleanArg &&Other) noexcept {}
