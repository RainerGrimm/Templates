#include <type_traits>
#include <iostream>
#include <string>

template<typename T>                                 
concept Arithmetic = std::is_arithmetic<T>::value;       

template <Arithmetic T, Arithmetic T2>
auto sum(T a, T2 b) {    
    return a + b;
}

int main() {
        
    std::cout << '\n';
    
    std::cout << "sum(2000, 11): " << sum(2000, 11) << '\n';
    std::cout << "sum(2000, 10.5): " << sum(2000, 10.5 ) << '\n';
    
    std::string hello("Hello");
    std::string world(" World");
    // std::cout << "sum(hello, world): " << sum(hello, world) << '\n';
    
    std::cout << '\n';
    
}
