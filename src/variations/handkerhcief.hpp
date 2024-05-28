#pragma once

#include "variations/variation.hpp"

struct Handkerchief : public Variation
{
    Handkerchief() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r = std::sqrt(x * x + y * y);
        const auto theta = std::atan(x / y);
        return {r * std::sin(theta + r), r * std::cos(theta - r)};
    }
};
