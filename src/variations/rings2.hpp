#pragma once

#include "variations/variation.hpp"

struct Rings2 : public Variation
{
    Rings2() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r = std::sqrt(x * x + y * y);
        const auto theta = std::atan(x / y);
        const auto t = r - 2.0 * p * std::trunc((r + p) / (2.0 * p)) + r * (1.0 - p);
        return {t * std::sin(theta), t * std::cos(theta)};
    }

    double p{}; // val
};
