#ifndef CT_MATH_HELPER_HPP
#define CT_MATH_HELPER_HPP
#include <limits>

namespace internal_use {

/*-------------------------------------------------------
Determine if given constexpr value is NaN

According to the IEEE standard, NaN values have the odd property that 
comparisons involving them are always false. 
That is, for a float f, f != f will be true only if f is NaN.
---------------------------------------------------------*/
template <typename T>
constexpr is_value_nan(const T a) -> const bool{
    return a != a;
}

/*-------------------------------------------------------
Determine if given constexpr value is infinite
Check value against +/- of inbuilt infinity function 
---------------------------------------------------------*/
constexpr is_value_inf(const T a) -> const bool{
    return ( (a != -std::numeric_limits<T>::infinity()) && (a != std::numeric_limits<T>::infinity()) )
}

};
#endif