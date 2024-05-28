#pragma once

#include "variations/variation.hpp"

struct Exponential : public Variation
{
    Exponential() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto e_to_xm1 = std::exp(x - 1);
        return {e_to_xm1 * std::cos(pi * y), e_to_xm1 * std::sin(pi * y)};
    }
};
