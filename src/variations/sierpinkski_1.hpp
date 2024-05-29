#pragma once

#include "variations/variation.hpp"

struct Sierpinkski1 : public Variation
{
    Sierpinkski1() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        return {(x + 1.0) / 2.0, y / 2.0};
    }
};
