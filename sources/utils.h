#pragma once

#include <functional>

template<typename T>
std::function<bool(T, T)> parseOperator(const std::string &op) {
    if (op == "<")
        return std::less<>{};
    else if (op == "<=") {
        return std::less_equal<>{};
    } else if (op == ">") {
        return std::greater<>{};
    } else if (op == ">=") {
        return std::greater_equal<>{};
    } else if (op == "==") {
        return std::equal_to<>{};
    } else if (op == "!=") {
        return std::not_equal_to<>{};
    } else
        throw std::invalid_argument("unidentified operator: " + op);
}