#include <iostream>

template<typename ...Args>
auto sum(Args&& ... args){
    return ( ... + args);
}

template<typename T, typename ...Args>
auto sumWithStart(T&& t, Args&& ... args){
    return ( t + ... + args);
}

int main(){

  std::cout << sum(1, 2, 3) << '\n';
  std::cout << sumWithStart(20, 1, 2, 3) << '\n';
  
}
