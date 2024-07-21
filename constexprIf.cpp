#include <iostream>
#include <type_traits>

// SFINAE

template <typename T, std::enable_if_t<std::is_arithmetic<T>{}>* = nullptr>
auto get_value_SFINAE(T) {
    std::cout << "get_Value_SFINAE(5)" << '\n';
}

template <typename T, std::enable_if_t<!std::is_arithmetic<T>{}>* = nullptr>
auto get_value_SFINAE(T) {
    std::cout << "get_Value_SFINAE(five)" << '\n';

}

// Tag dispatch

template <typename T>
auto get_value_TAG_DISPATCH(T, std::true_type) {
     std::cout << "get_Value_TAG_DISPATCH(5)" << '\n';
}

template <typename T>
auto get_value_TAG_DISPATCH(T, std::false_type) {
    std::cout << "get_Value_TAG_DISPATCH(five)" << '\n';
}

template <typename T>
auto get_value_TAG_DISPATCH(T t) {
    return get_value_TAG_DISPATCH(t, std::is_arithmetic<T>{});
}

// constexpr if

template <typename T>
auto get_value_CONSTEXPR_IF(T) {
     if constexpr (std::is_arithmetic_v<T>) {
         std::cout << "get_Value_CONSTEXPR_IF(5)" << '\n';
     }
     else {
         std::cout << "get_Value_CONSTEXPR_IF(five)" << '\n';
     }
}

int main(){
    
    std::cout << '\n';
    
    get_value_SFINAE(5);
    get_value_SFINAE("five");
    
    std::cout << '\n';
    
    get_value_TAG_DISPATCH(5);
    get_value_TAG_DISPATCH("five");
    
    std::cout << '\n';
    
    get_value_CONSTEXPR_IF(5);
    get_value_CONSTEXPR_IF("five");
    
    std::cout << '\n';
    
}
