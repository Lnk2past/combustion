#pragma once

#include "variations/variation.hpp"

struct Polar : public Variation
{
    Polar() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        using namespace std::numbers;
        const auto theta = std::atan(x / y);
        const auto r = std::sqrt(x * x + y * y);
        return {theta / pi, r - 1};
    }
};
