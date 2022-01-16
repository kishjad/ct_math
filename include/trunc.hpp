#ifndef CT_MATH_TRUNC_HPP
#define CT_MATH_TRUNC_HPP
#include <helper_functions.hpp>

namespace trunc_operator{

    template <typename T>
    constexpr T trunc_check(const T a) noexcept{
        static_assert(std::is_arithmetic_v<T>, "Invalid argument to trunc");
        static_assert(internal_use::is_constant_evaluated(), "trunc is not constexpr");
        if (internal_use::is_value_nan(a)) {
            return std::numeric_limits<T>::quiet_NaN();
        }
        else if (internal_use::is_value_inf(a)){
            return a;
        }
        return T(static_cast<long long int>(a));
    }
};


template<typename T>
constexpr auto trunc(const T x) -> typename std::conditional<std::is_integral_v<T>, double, T>::type
{
    return trunc_operator::trunc_check( static_cast<typename std::conditional<std::is_integral_v<T>, double, T>::type>(x) );
}
#endif 