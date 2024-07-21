#include <iostream>

template<typename T>
T gcd(T a, T b){
  if( b == 0 ){ return a; }
  else{
    return gcd(b, a % b);
  }
}

int main(){

  std::cout << '\n';

  std::cout << "gcd(100,10)= " <<  gcd(100,10)  << '\n';
  std::cout << "gcd(100,33)= " << gcd(100,33) << '\n';
  std::cout << "gcd(100,0)= " << gcd(100,0)  << '\n';

  std::cout << gcd(3.5,4.0)<< '\n';
  std::cout << gcd("100","10") << '\n';

  std::cout << gcd(100,10L) << gcd(100,10L) << '\n';

  std::cout << '\n';

}
