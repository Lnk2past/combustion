#pragma once

#include "variations/variation.hpp"

struct Power : public Variation
{
    Power() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r = std::sqrt(x * x + y * y);
        const auto theta = std::atan(x / y);
        const auto coeff = std::pow(r, std::sin(theta));
        return {coeff * std::cos(theta), coeff * std::sin(theta)};
    }
};
