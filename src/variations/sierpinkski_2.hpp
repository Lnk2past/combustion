#pragma once

#include "variations/variation.hpp"

struct Sierpinkski2 : public Variation
{
    Sierpinkski2() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        return {x / 2.0, (y + 1.0) / 2.0};
    }
};
