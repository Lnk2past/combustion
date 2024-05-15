#include <random>

#include <spdlog/spdlog.h>

#include "flame.hpp"
#include "variations/all.hpp"

auto Flame::compute(const int iterations, std::vector<Transform> &transforms) -> std::vector<std::array<double, 4>>
{
    // auto t1 = Transform();
    // auto v1 = Halve();
    // t1.add_variation(&v1);
    // auto t2 = Transform();
    // auto v2 = Sierpinkski1();
    // t2.add_variation(&v2);
    // auto t3 = Transform();
    // auto v3 = Sierpinkski2();
    // t3.add_variation(&v3);
    // transforms = {t1, t2, t3};

    auto engine = std::mt19937{1337};
    auto unit_distribution = std::uniform_real_distribution{0.0, 1.0};
    auto biunit_distribution = std::uniform_real_distribution{-1.0, 1.0};
    auto transform_distribution = std::uniform_int_distribution{0, static_cast<int>(transforms.size() - 1)};

    auto i = std::array{biunit_distribution(engine), biunit_distribution(engine), unit_distribution(engine), 0.0};
    for (auto iteration = 0; iteration < 20; ++iteration)
    {
        auto &tx = transforms[transform_distribution(engine)];
        i = tx.compute(i);
    }

    auto solution = std::vector<std::array<double, 4>>(iterations);
    solution[0] = transforms[transform_distribution(engine)].compute(i);
    for (auto iteration = 1; iteration < iterations; ++iteration)
    {
        auto &tx = transforms[transform_distribution(engine)];
        solution[iteration] = tx.compute(solution[iteration - 1]);
        i = tx.compute(i);
    }
    return solution;
}
