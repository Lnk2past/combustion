#pragma once

#include "variations/variation.hpp"

struct Spiral : public Variation
{
    Spiral() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r = std::sqrt(x * x + y * y);
        const auto theta = std::atan(x / y);
        const auto one_over_r = 1.0 / r;
        return {one_over_r * (std::cos(theta) + std::sin(r)), one_over_r * (std::sin(theta) - std::cos(r))};
    }
};
