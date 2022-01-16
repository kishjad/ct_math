#ifndef CT_MATH_rint_HPP
#define CT_MATH_rint_HPP
#include <helper_functions.hpp>
#include <fenv.h>

/*
If the current rounding mode is...

    FE_DOWNWARD, then rint is equivalent to floor.
    FE_UPWARD, then rint is equivalent to ceil.
    FE_TOWARDZERO, then rint is equivalent to trunc
    FE_TONEAREST, then rint differs from round in that halfway cases are rounded to even rather than away from zero. 

*/

/*
For the rint function: 
If arg is ±∞, it is returned, unmodified
If arg is ±0, it is returned, unmodified
If arg is NaN, NaN is returned 
*/
namespace rint{
        template <typename T>
        constexpr int checkOperator (const T a){
            return ( ( (a>T(0)) && (T(static_cast<long long int>(a)) != a)) ? 1 : 0);
        }
    
        template <typename T>
        constexpr T rint_check(const T a) noexcept{
            static_assert(std::is_arithmetic_v<T>, "Invalid argument to rint");
            static_assert(internal_use::is_constant_evaluated(), "rint is not constexpr");
            if (internal_use::is_value_nan(a)) {
                return std::numeric_limits<T>::quiet_NaN();
            }
            else if (internal_use::is_value_inf(a)){
                return a;
            }
            else if(a == T(0)){
                return T(0);
            }
            return T(static_cast<long long int>(a + (checkOperator<T>(a)) ));
        }
    };
}

template<class T,
    std::enable_if_t<std::is_floating_point<T>::value, bool> = true
>
constexpr auto rint(const T x) -> T
{
    return rint_operator::rint_check( static_cast<T>(x) );
}

#endif