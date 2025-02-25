#include <iostream>
#include <type_traits>

template<typename T,
         typename std::enable_if<std::is_integral<T>::value,T>::type= 0>       
T gcd(T a, T b){
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

int main(){

  std::cout << '\n';

  std::cout << "gcd(100, 10)= " <<  gcd(100, 10)  << '\n';
  std::cout << "gcd(3.5, 4)= " << gcd(3.5, 4.0) << '\n';     

  std::cout << '\n';

}
