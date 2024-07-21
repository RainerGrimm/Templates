#include <iostream>

template<typename... Args>
bool all(Args... args) { return (... && args); }

template<typename... Args>
bool any(Args... args) { return (... || args); }

template<typename... Args>
bool none(Args... args) { return not(... || args); }


int main(){
    
  std::cout << '\n';

  std::cout << std::boolalpha;

  std::cout << "all(true): " << all(true) << '\n';
  std::cout << "any(true): " << any(true) << '\n';
  std::cout << "none(true): " << none(true) << '\n';
  
  std::cout << '\n';

  std::cout << "all(true, true, true, false): " << all(true, true, true, false) << '\n';
  std::cout << "any(true, true, true, false): " << any(true, true, true, false) << '\n';
  std::cout << "none(true, true, true, false): " << none(true, true, true, false) << '\n';
  
  std::cout << '\n';
  
  std::cout << "all(false, false, false, false): " << all(false, false, false, false) << '\n';
  std::cout << "any(false, false, false, false): " << any(false, false, false, false) << '\n';
  std::cout << "none(false, false, false, false): " << none(false, false, false, false) << '\n';
  
  std::cout << '\n';
  
}
