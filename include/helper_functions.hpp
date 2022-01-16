#ifndef CT_MATH_HELPER_HPP
#define CT_MATH_HELPER_HPP
#include <limits>
namespace internal_use {


#if __cplusplus >= 202002L
#include <type_traits>
#endif
constexpr bool is_constant_evaluated() {
#if __cplusplus >= 202002L
    return std::is_constant_evaluated();
#elif defined(__GNUC__) // defined for both GCC and clang
    return __builtin_is_constant_evaluated();
#else
    // If the builtin is not available, return a pessimistic result.
    // This way callers will implement everything in a constexpr way.
    return true;
#endif
}


/*-------------------------------------------------------
Determine if given constexpr value is NaN

According to the IEEE standard, NaN values have the odd property that 
comparisons involving them are always false. 
That is, for a float f, f != f will be true only if f is NaN.
---------------------------------------------------------*/
template <typename T>
constexpr bool is_value_nan(const T a) noexcept{
    return a != a;
}

/*-------------------------------------------------------
Determine if given constexpr value is infinite
Check value against +/- of inbuilt infinity function 
---------------------------------------------------------*/
template <typename T>
constexpr bool is_value_inf(const T a) noexcept{
    return ( (a == -std::numeric_limits<T>::infinity()) && (a == std::numeric_limits<T>::infinity()) );
}

};
#endif