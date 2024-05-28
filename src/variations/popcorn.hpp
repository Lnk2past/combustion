#pragma once

#include "variations/variation.hpp"

struct Popcorn : public Variation
{
    Popcorn() = default;

    auto compute(const double, const double, const double c, const double, const double, const double f, const double x, const double y) const -> std::array<double, 2> const
    {
        return {
            x + c * std::sin(std::tan(3.0 * y)),
            y + f * std::sin(std::tan(3.0 * x))};
    }
};
