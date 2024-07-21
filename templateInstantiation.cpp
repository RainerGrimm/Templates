#include <iostream>
#include <vector>

template <typename T, int N>
class Array{

public:
  Array()= default;

  int getSize() const{
      return N;
  }

  std::vector<T> elem;
};

template<typename T>
bool isSmaller(T fir, T sec){
  return fir < sec;
}

template class std::vector<int>;
template bool std::vector<double>::empty() const;

template class Array<int, 20>;
template int Array<double, 5>::getSize() const;

template bool isSmaller(double, double);
template bool isSmaller<int>(int, int);

int main(){

  std::cout << '\n';
  
  std::cout << std::boolalpha << "implicit" << '\n';
  
  std::cout << '\n';
  
  std::vector<int> vec{};
  std::cout << "vec.size(): " << vec.size() << '\n';
  
  Array<int, 10> arr;
  std::cout << "arr.getSize(): " << arr.getSize() << '\n';
  
  std::cout << '\n';
  
  std::cout << "isSmaller(5, 10): " << isSmaller(5,10) << '\n';
  
  std::cout << "isSmaller<double>(5.5, 6.5): " << isSmaller<double>(5.5, 6.5) << '\n';
  
  std::cout << '\n';
  
}
