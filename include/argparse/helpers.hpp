/**
 * @file helpers.hpp
 * @brief Contains some help functions
 *
 * @version 1.0.0
 * @date 2026-01-29
 * @authors Eugene Azimut (y.azimut@mail.ru)
 * @copyright Copyright (c) Eugene Azimut, 2026
 *
 */
#pragma once
#include "api.hpp"



namespace argparse {
    /**
     * @brief Replaces the value of Obj with NewValue and returns the old value of Obj
     *
     * @tparam T Basic C++ type
     * @tparam U Basic C++ type
     * @param[in,out] Obj Object whose value to replace
     * @param[in] NewValue The value to assign to Obj
     * @return The old value of Obj
     *
     * @version 1.0.0
     * @authors Eugene Azimut
     */
    template<typename T, typename U = T>
    ARGPARSE_API T exchange_basic(T &Obj, U NewValue) {
        T tmp = Obj;
        Obj = NewValue;
        return tmp;
    }
}
