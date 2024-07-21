#include <iostream>
#include <vector>

template<typename T>                                 
concept Arithmetic = std::is_arithmetic<T>::value; 

template<Arithmetic T>
T sum(const std::vector<T>& cont, T s) {
    for (auto x : cont) s += x;   
    return s;
}

int main() {
    
    std::cout << '\n';
    
    std::vector vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    std::cout << "sum(vec, 0): " << sum(vec, 0) << '\n';
    std::cout << "sum(vec, 10): " << sum(vec, 10) << '\n';

} 