#include <iostream>

template<typename T>
T gcd(T a, T b) {
    if( b == 0 ){ return a; }
    else{
        return gcd(b, a % b);
    }
}

int main() {

    std::cout << gcd(100, 10);
    std::cout << gcd(3.5, 4.0);
    
}
