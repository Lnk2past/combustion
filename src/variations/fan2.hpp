#pragma once

#include "variations/variation.hpp"

struct Fan2 : public Variation
{
    Fan2() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r = std::sqrt(x * x + y * y);
        const auto theta = std::atan(x / y);
        const auto p1 = pi * x * x;
        const auto p2 = pi * y * y;
        const auto t = theta + p2 - p1 * std::trunc(2.0 * theta * p2 / p1);
        if (t > 0.5 * p1)
        {
            const auto var = theta - p1 * 0.5;
            return {r * std::sin(var), r * std::cos(var)};
        }
        const auto var = theta + p1 * 0.5;
        return {r * std::sin(var), r * std::cos(var)};
    }
};
