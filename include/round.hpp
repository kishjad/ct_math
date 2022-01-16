
#ifndef CT_MATH_round_HPP
#define CT_MATH_round_HPP
#include <helper_functions.hpp>

namespace round_operator{

    template <typename T>
    constexpr int checkOperator (const T a){
        if(a>=T(0)){
            return ( (a - ct_math::trunc(a) >= T(0.5)) ? 1 : 0);
        }
        else{
            return ( (a - ct_math::trunc(a) <= T(-0.5)) ? 1 : 0);
        }
    }

    template <typename T>
    constexpr T round_check(const T a) noexcept{
        static_assert(std::is_arithmetic_v<T>, "Invalid argument to round");
        static_assert(internal_use::is_constant_evaluated(), "round is not constexpr");
        if (internal_use::is_value_nan(a)) {
            return std::numeric_limits<T>::quiet_NaN();
        }
        else if (internal_use::is_value_inf(a)){
            return a;
        }
        else if(std::is_integral_v<T>){
            return T(static_cast<long long int>(a));
        }
        return T(static_cast<long long int>(a + (checkOperator<T>(a)) ));
    }
};


template<typename T>
constexpr auto round(const T x) -> typename std::conditional<std::is_integral_v<T>, double, T>::type
{
    return round_operator::round_check( static_cast<typename std::conditional<std::is_integral_v<T>, double, T>::type>(x) );
}
#endif 