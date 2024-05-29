#pragma once

#include "variations/variation.hpp"

struct JuliaN : public Variation
{
    JuliaN() = default;

    auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const
    {
        const auto r = std::sqrt(x * x + y * y);
        auto rd = std::random_device{};
        const auto psi = std::uniform_real_distribution<double>{0.0, 1.0}(rd);
        const auto p3 = std::trunc(std::abs(p1) * psi);
        const auto t = (phi + 2.0 * pi * p3) / p1;
        const auto coeff = std::pow(r, p2 / p1);
        return {coeff * std::cos(t), coeff * std::sin(t)};
    }
    double p1{}; // power
    double p2{}; // dist
};
