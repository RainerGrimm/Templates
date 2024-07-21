#include <iostream>
#include <string>

template <typename T>
T min(T fir, T sec){
  return (fir < sec) ? fir : sec;
}

template <>
bool min<bool>(bool fir, bool sec){
  return fir & sec;
}

int main(){

  std::cout << std::boolalpha << '\n';

  std::cout << "min(3.5, 4,5): "  << min(3.5, 4.5) << '\n';
  std::cout << "min<double>(3.5, 4,5): "  << min<double>(3.5, 4.5) << '\n';

  std::cout << "min(true, false): "  << min(true, false) << '\n';
  std::cout << "min<bool>(true, false): "  << min<bool>(true, false) << '\n';

  std::cout << '\n';

}
