#pragma once

#include "variations/variation.hpp"

struct Wave : public Variation
{
    Wave() = default;

    auto compute(const double, const double b, const double c, const double, const double e, const double f, const double x, const double y) const -> std::array<double, 2> const
    {
        return {x + b * std::sin(y / c / c), y + e * std::sin(x / f / f)};
    }
};
