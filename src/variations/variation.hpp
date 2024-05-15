#pragma once

class Variation
{
public:
    virtual ~Variation() = default;

    virtual auto compute(const double, const double, const double, const double, const double, const double, const std::array<double, 4> &xyc) const -> std::array<double, 4> const = 0;
};
