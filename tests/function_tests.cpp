#include "catch.hpp"
#include <ct_math.hpp>
#include <cmath>

SCENARIO("Check constexpr floor values")
{
    GIVEN("Floating values")
    {
        CHECK(ct_math::floor(10.35) == std::floor(10.35));
        CHECK(ct_math::floor(-10.35) == std::floor(-10.35));
        CHECK(ct_math::floor(-10) == std::floor(-10));
        CHECK(ct_math::floor(10.) == std::floor(10.));
    }
};

SCENARIO("Check constexpr ceil values")
{
    GIVEN("Floating values")
    {
        CHECK(ct_math::ceil(10.35) == std::ceil(10.35));
        CHECK(ct_math::ceil(-10.35) == std::ceil(-10.35));
        CHECK(ct_math::ceil(-10) == std::ceil(-10));
        CHECK(ct_math::ceil(10.) == std::ceil(10.));
    }
}