#include <array>
#include <vector>

#include "transforms/transform.hpp"

class Flame
{
public:
    Flame() = default;

    auto compute(const int iterations, std::vector<Transform> &transforms) -> std::vector<std::array<double, 4>>;
};
