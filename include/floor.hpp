
#ifndef CT_MATH_FLOOR_HPP
#define CT_MATH_FLOOR_HPP

namespace floor_operator{
    template <typename T>
    constexpr int checkOperator (const T a){
        return ( ( (a<T(0)) && (T(static_cast<long long int>(a)) != a)) ? 1 : 0);
    }

    template <typename T>
    constexpr T floor_check(const T a) noexcept{
        if constexpr(std::is_integral<T>::value){
            return T(static_cast<long long int>(a));
        }
        return T(static_cast<long long int>(a - (checkOperator<T>(a)) ));
    }
}


template<typename T>
constexpr auto replace_floor(const T x) -> const T
{
    return floor_operator::floor_check( static_cast<T>(x) );
}
#endif 