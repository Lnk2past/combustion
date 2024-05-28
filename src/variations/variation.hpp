#pragma once

#include <array>
#include <cmath>
#include <numbers>
#include <random>

using namespace std::numbers;

class Variation
{
public:
    virtual ~Variation() = default;

    virtual auto compute(const double, const double, const double, const double, const double, const double, const double x, const double y) const -> std::array<double, 2> const = 0;
};
