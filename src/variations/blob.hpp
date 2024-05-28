#pragma once

#include "variations/variation.hpp"

struct Blob : public Variation
{
    Blob() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r = std::sqrt(x * x + y * y);
        const auto theta = std::atan(x / y);
        const auto coeff = r * (p2 + 0.5 * (p1 - p2) * (std::sin(p3 * theta) + 1));
        return {coeff * std::cos(theta), coeff * std::sin(theta)};
    }

    double p1{}; // high
    double p2{}; // low
    double p3{}; // waves
};
