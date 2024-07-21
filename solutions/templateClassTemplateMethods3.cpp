#include <initializer_list>
#include <iostream>
#include <list>
#include <vector>

template <typename T, template <typename, typename> class Cont = std::vector>
class Matrix{
public:
  explicit Matrix(std::initializer_list<T> inList): data(inList){
    for (auto d: data) std::cout << d << " ";
  }
  int getSize() const{
    return data.size();
  }

private:
  Cont<T, std::allocator<T>> data;

};

int main(){

  std::cout << '\n';

  Matrix<int> myIntVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << '\n';
  std::cout << "myIntVec.getSize(): " << myIntVec.getSize() << '\n';

  std::cout << '\n';

  Matrix<double> myDoubleVec{1.1, 2.2, 3.3, 4.4, 5.5};
  std::cout << '\n';
  std::cout << "myDoubleVec.getSize(): "  << myDoubleVec.getSize() << '\n';

  std::cout << '\n';

  Matrix<std::string,std::list> myStringList{"one", "two", "three", "four"};
  std::cout << '\n';
  std::cout << "myStringList.getSize(): " << myStringList.getSize() << '\n';

  std::cout << '\n';

}
