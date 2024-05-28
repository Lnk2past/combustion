#pragma once

#include "variations/variation.hpp"

struct Fan : public Variation
{
    Fan() = default;

    auto compute(const double, const double, const double c, const double, const double, const double f, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r = std::sqrt(x * x + y * y);
        const auto theta = std::atan(x / y);
        const auto t = pi * c * c;
        if (std::fmod(f + theta, t) > t * 0.5)
        {
            const auto var = theta - t * 0.5;
            return {r * std::cos(var), r * std::sin(var)};
        }
        const auto var = theta + t * 0.5;
        return {r * std::cos(var), r * std::sin(var)};
    }
};
