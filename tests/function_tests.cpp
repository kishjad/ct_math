#include "catch.hpp"
#include <ct_math.hpp>
#include <cmath>

SCENARIO("Check constexpr floor values")
{
    GIVEN("Floating values")
    {
        constexpr float val1 = 10.35; 
        CHECK(ct_math::floor(val1) == std::floor(val1));
    }
};

SCENARIO("Check constexpr ceil values")
{
    GIVEN("Floating values")
    {
        constexpr float val1 = 10.35; 
        CHECK(ct_math::ceil(val1) == std::ceil(val1));
    }
}