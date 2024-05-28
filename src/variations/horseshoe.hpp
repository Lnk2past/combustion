#pragma once

#include "variations/variation.hpp"

struct Horseshoe : public Variation
{
    Horseshoe() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto odr = 1.0 / std::sqrt(x * x + y * y);
        return {odr * (x - y) * (x + y), odr * 2.0 * x * y};
    }
};
