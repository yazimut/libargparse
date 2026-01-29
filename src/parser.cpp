/**
 * @file parser.cpp
 * @brief Definition of CLI arguments parser
 *
 * @version 1.0.0
 * @date 2026-01-07
 * @authors Eugene Azimut (y.azimut@mail.ru)
 * @copyright Copyright (c) Eugene Azimut, 2026
 *
 */
#include <argparse/parser.hpp>

using namespace argparse;



ArgumentParser::ArgumentParser(ErrorAction OnError):
  mOnErrorAction(OnError) {}

ArgumentParser::ArgumentParser(const ArgumentParser &Other) {
    *this = Other;
}

ArgumentParser::~ArgumentParser() {}

ArgumentParser &ArgumentParser::operator = (const ArgumentParser &Right) {
    mOnErrorAction = Right.mOnErrorAction;

    return *this;
}

void ArgumentParser::addArgument() {}

ArgumentParser::ErrorAction ArgumentParser::getErrorAction() const {
    return mOnErrorAction;
}

void ArgumentParser::setErrorAction(ErrorAction OnError) {
    mOnErrorAction = OnError;
}
