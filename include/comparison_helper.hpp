#ifndef COMPARSIONS_HPP
#define COMPARSIONS_HPP
#include <math.h>
#include <limits>
#include <type_traits>
/*
std::fabs(a-b) < epsilon 
This method has many weaknesses, like if the numbers a and b are already smaller than epsilon() 
their difference may still be significant. 
Conversely if the numbers are very large then even a couple of bits of error will make the comparison fail even 
if you did want the numbers to be considered equal. 
*/

template <class T,
       std::enable_if_t<std::is_floating_point<T>::value, bool> = true
>
bool approximatelyEqual(T a, T b, T epsilon = std::numeric_limits<T>::epsilon())
{
    return fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

template<class T,
    std::enable_if_t<std::is_floating_point<T>::value, bool> = true
>
bool essentiallyEqual(T a, T b, T epsilon = std::numeric_limits<T>::epsilon())
{
    return fabs(a - b) <= ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

template<class T,
    std::enable_if_t<std::is_floating_point<T>::value, bool> = true
>
bool definitelyGreaterThan(T a, T b, T epsilon = std::numeric_limits<T>::epsilon())
{
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

template<class T,
    std::enable_if_t<std::is_floating_point<T>::value, bool> = true
>
bool definitelyLessThan(T a, T b,T epsilon = std::numeric_limits<T>::epsilon())
{
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

template<class T,
    std::enable_if_t<std::is_floating_point<T>::value, bool> = true
>
bool definitelyLessThanOrEqual(T a, T b)
{
    return(definitelyLessThan<T>(a,b) || essentiallyEqual<T>(a,b));
}

template<class T,
    std::enable_if_t<std::is_floating_point<T>::value, bool> = true
>
bool definitelyGreaterThanOrEqual(T a, T b)
{
    return(definitelyGreaterThan<T>(a,b) || essentiallyEqual<T>(a,b));
}

#endif