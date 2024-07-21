#include <iostream>

template<int m, int n>
int powerIf(){
    if constexpr(n == 0)  return 1;
    else return powerIf<m,n-1>() * m;
};


int main(){
    
    std::cout << '\n';
    
    std::cout << "powerIf<2,10>(): " << powerIf<2,10>() << '\n';
    
    std::cout << '\n';
}
