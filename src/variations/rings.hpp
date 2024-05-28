#pragma once

#include "variations/variation.hpp"

struct Rings : public Variation
{
    Rings() = default;

    auto compute(const double, const double, const double c, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r = std::sqrt(x * x + y * y);
        const auto theta = std::atan(x / y);
        const auto c_squared = c * c;
        const auto coeff = std::fmod(r + c_squared, 2 * c_squared) - c_squared + r * (1 - c_squared);
        return {coeff * std::cos(theta), coeff * std::sin(theta)};
    }
};
