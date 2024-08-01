#include <iostream>
#include <typeinfo>
#include <type_traits>

template <typename T, typename T2>
typename std::common_type<T, T2>::type sum(T t, T2 t2) {
    return t + t2;
}


int main() {

    std::cout << '\n';

    std::cout << typeid(sum(5.5, 5.5)).name() << '\n';     
    std::cout << typeid(sum(5.5, true)).name() << '\n';    
    std::cout << typeid(sum(true, 5.5)).name() << '\n';    
    std::cout << typeid(sum(true, false)).name() << '\n';  

    std::cout << '\n';

}