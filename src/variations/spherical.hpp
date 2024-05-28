#pragma once

#include "variations/variation.hpp"

struct Spherical : public Variation
{
    Spherical() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r2 = x * x + y * y;
        return {x / r2, y / r2};
    }
};
