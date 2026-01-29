/**
 * @file StringArg.cpp
 * @brief Definition of string CLI argument
 *
 * @version 1.0.0
 * @date 2026-01-29
 * @authors Eugene Azimut (y.azimut@mail.ru)
 * @copyright Copyright (c) Eugene Azimut, 2026
 *
 */
#include <argparse/args/StringArg.hpp>

using namespace std;
using namespace argparse;



StringArg::StringArg(
    const string &Flags, const string &Help,
    bool IsRequired, bool IsDeprecated):
IArgument(Flags, Help, IsRequired, IsDeprecated) {}

StringArg::StringArg(const StringArg &Other):
IArgument(Other) {
    selfCopy(Other);
}

StringArg::StringArg(StringArg &&Other) noexcept:
IArgument(move(Other)) {
    selfMove(move(Other));
}

StringArg::~StringArg() {}

StringArg &StringArg::operator = (const StringArg &Right) {
    if (this == &Right) return *this;

    *static_cast<IArgument *>(this) = Right;
    selfCopy(Right);
    return *this;
}

StringArg &StringArg::operator = (StringArg &&Right) noexcept {
    if (this == &Right) return *this;

    *static_cast<IArgument *>(this) = move(Right);
    selfMove(move(Right));
    return *this;
}

void StringArg::selfCopy(const StringArg &Other) {}

void StringArg::selfMove(StringArg &&Other) noexcept {}
