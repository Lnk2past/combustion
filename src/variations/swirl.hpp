#pragma once

#include "variations/variation.hpp"

struct Swirl : public Variation
{
    Swirl() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r2 = x * x + y * y;
        return {x * std::sin(r2) - y * std::cos(r2), x * std::cos(r2) + y * std::sin(r2)};
    }
};
