#include <iostream>

int power(int m, int n){
    int r = 1;
    for(int k=1; k<=n; ++k) r*= m;
    return r;
}

template<int m, int n>
struct Power{
    static const int value = Power<m,n-1>::value * m;
};

template<int m>
struct Power<m,0>{
    static const int value = 1;
};

template<int n>
int power(int m){
    return power<n-1>(m) * m;
}

template<>
int power<0>(int){
    return 1;
}

int main(){
    
    std::cout << '\n';
    
    std::cout << "power(2,10):        " << power(2,10) << '\n';
    std::cout << "power<10>(2):       " << power<10>(2) << '\n';
    std::cout << "Power<2,10>::value: " << Power<2,10>::value << '\n';
    
    std::cout << '\n';
}
