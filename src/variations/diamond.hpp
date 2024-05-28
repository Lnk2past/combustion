#pragma once

#include "variations/variation.hpp"

struct Diamond : public Variation
{
    Diamond() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r = std::sqrt(x * x + y * y);
        const auto theta = std::atan(x / y);
        return {std::sin(theta) * std::cos(r), std::cos(theta) * std::sin(r)};
    }
};
