
#ifndef CT_MATH_FLOOR_HPP
#define CT_MATH_FLOOR_HPP
#include <helper_functions.hpp>

namespace floor_operator{

    template <typename T>
    constexpr int checkOperator (const T a){
        return ( ( (a<T(0)) && (T(static_cast<long long int>(a)) != a)) ? 1 : 0);
    }

    template <typename T>
    constexpr T floor_check(const T a) noexcept{
        static_assert(std::is_arithmetic_v<T>, "Value passed to floor is not a integer or float");

        if constexpr(internal_use::is_value_nan(a)) {
            return std::numeric_limits<T>::quiet_NaN();
        }
        else if constexpr(internal_use::is_value_inf(a)){
            return a;
        }
        else(std::is_integral<T>::value){
            return T(static_cast<long long int>(a));
        }
        return T(static_cast<long long int>(a - (checkOperator<T>(a)) ));
    }
};


template<typename T>
constexpr auto floor(const T x) -> const T
{
    return floor_operator::floor_check( static_cast<T>(x) );
}
#endif 