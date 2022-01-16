#include "catch.hpp"
#include <ct_math.hpp>
#include <cmath>
#include "ct_math_test_helper.hpp"
SCENARIO("Check constexpr floor values")
{
    GIVEN("Floating values")
    {
        CHECK(ct_math::floor(10.35) == std::floor(10.35));
        CHECK(ct_math::floor(-10.35) == std::floor(-10.35));
        CHECK(ct_math::floor(-10) == std::floor(-10));
        CHECK(ct_math::floor(10.) == std::floor(10.));
        CHECK(approximatelyEqual(ct_math::floor(-std::numeric_limits<long double>::infinity()), std::floor( -std::numeric_limits<long double>::infinity()))  );
        CHECK(approximatelyEqual(ct_math::floor( std::numeric_limits<long double>::infinity()) , std::floor( std::numeric_limits<long double>::infinity()))  );
        CHECK( std::isnan(static_cast<long double>( (ct_math::floor( std::numeric_limits<long double>::quiet_NaN()) ))) );
        CHECK( std::isnan(static_cast<float>( (ct_math::floor( std::numeric_limits<float>::quiet_NaN()) ))) );
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
        CHECK(approximatelyEqual(ct_math::ceil(-std::numeric_limits<long double>::infinity()), std::ceil( -std::numeric_limits<long double>::infinity()))  );
        CHECK(approximatelyEqual(ct_math::ceil( std::numeric_limits<long double>::infinity()) , std::ceil( std::numeric_limits<long double>::infinity()))  );
        CHECK( std::isnan(static_cast<long double>( (ct_math::ceil( std::numeric_limits<long double>::quiet_NaN()) ))) );
        CHECK( std::isnan(static_cast<float>( (ct_math::ceil( std::numeric_limits<float>::quiet_NaN()) ))) );
    }
}

SCENARIO("Check constexpr trunc values")
{
    GIVEN("Floating values")
    {
        CHECK(ct_math::trunc(10.35) == std::trunc(10.35));
        CHECK(ct_math::trunc(-10.35) == std::trunc(-10.35));
        CHECK(ct_math::trunc(-10) == std::trunc(-10));
        CHECK(ct_math::trunc(10.) == std::trunc(10.));
        CHECK(approximatelyEqual(ct_math::trunc(-std::numeric_limits<long double>::infinity()), std::trunc( -std::numeric_limits<long double>::infinity()))  );
        CHECK(approximatelyEqual(ct_math::trunc( std::numeric_limits<long double>::infinity()) , std::trunc( std::numeric_limits<long double>::infinity()))  );
        CHECK( std::isnan(static_cast<long double>( (ct_math::trunc( std::numeric_limits<long double>::quiet_NaN()) ))) );
        CHECK( std::isnan(static_cast<float>( (ct_math::trunc( std::numeric_limits<float>::quiet_NaN()) ))) );
    }
}