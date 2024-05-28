#pragma once

#include "variations/variation.hpp"

struct Disc : public Variation
{
    Disc() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        using namespace std::numbers;
        const auto r = std::sqrt(x * x + y * y);
        const auto theta_over_pi = std::atan(x / y) / pi;
        return {theta_over_pi * std::sin(r * pi), theta_over_pi * std::cos(r * pi)};
    }
};
