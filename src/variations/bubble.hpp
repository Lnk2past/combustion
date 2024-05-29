#pragma once

#include "variations/variation.hpp"

struct Bubble : public Variation
{
    Bubble() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r2 = x * x + y * y;
        const auto coeff = 4.0 / (r2 + 4.0);
        return {coeff * x, coeff * y};
    }
};
