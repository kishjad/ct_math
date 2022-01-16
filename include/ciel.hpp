
#ifndef CT_MATH_CEIL_HPP
#define CT_MATH_CEIL_HPP
#include <helper_functions.hpp>

namespace ceil_operator{

    template <typename T>
    constexpr int checkOperator (const T a){
        return ( ( (a<T(0)) && (T(static_cast<long long int>(a)) != a)) ? 1 : 0);
    }

    template <typename T>
    constexpr T floor_check(const T a) noexcept{
        static_assert(std::is_arithmetic_v<T>, "Invalid argument to floor");
        static_assert(internal_use::is_constant_evaluated(), "floor is not constexpr");
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
constexpr auto ceil(const T x) -> const T
{
    return ceil_operator::ciel_check( static_cast<T>(x) );
}
#endif 