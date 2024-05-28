#pragma once

#include "variations/variation.hpp"

struct Ex : public Variation
{
    Ex() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r = std::sqrt(x * x + y * y);
        const auto theta = std::atan(x / y);
        auto p0 = std::sin(theta + r);
        auto p1 = std::cos(theta - r);
        auto p0_cubed = p0 * p0 * p0;
        auto p1_cubed = p1 * p1 * p1;
        return {r * (p0_cubed + p1_cubed), r * (p0_cubed - p1_cubed)};
    }
};
