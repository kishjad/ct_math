
#ifndef CT_MATH_FMOD_HPP
#define CT_MATH_FMOD_HPP
#include <helper_functions.hpp>

namespace fmod_operator{

    template <typename T>
    constexpr int checkOperator (const T a){
        return ( ( (a<T(0)) && (T(static_cast<long long int>(a)) != a)) ? 1 : 0);
    }

    template <typename T1, typename T2, typename T3 = std::common_type<T1, T2>::type> >
    constexpr T3 fmod_check(const T1 a, const T2 b) noexcept{
        static_assert(std::is_arithmetic_v<T>, "Invalid argument to fmod");
        static_assert(internal_use::is_constant_evaluated(), "fmod is not constexpr");
        if (internal_use::is_value_nan(a)) {
            return std::numeric_limits<T>::quiet_NaN();
        }
        else if (internal_use::is_value_inf(a)){
            return a;
        }
        else if(std::is_integral_v<T>){
            return T(static_cast<long long int>(a));
        }
        return T(static_cast<long long int>(a - (checkOperator<T>(a)) ));
    }
};


template <typename T1, typename T2 >
constexpr auto fmod(const T1 a, const T2 b) -> typename std::common_type<T1, T2>::type
{
    return fmod_operator::fmod_check( static_cast<T>(x) , static_cast<T>(y) );
}
#endif 