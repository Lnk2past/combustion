#pragma once

#include "variations/variation.hpp"

struct Hyperbolic : public Variation
{
    Hyperbolic() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r = std::sqrt(x * x + y * y);
        const auto theta = std::atan(x / y);
        return {std::sin(theta) / r, r * std::cos(theta)};
    }
};
