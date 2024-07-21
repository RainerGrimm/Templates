#include <iostream>


template <typename T=std::string, int Line=10, int Column=Line>
class Matrix{
public:
  int numberOfElements() const;
};

template <typename T, int Line, int Column>
int Matrix<T,Line,Column>::numberOfElements() const {
  return Line * Column;
}


template <typename T>
class Matrix<T,3,3>{
public:
  int numberOfElements() const;
};

template <typename T>
int Matrix<T,3,3>::numberOfElements() const {
  return 3*3;
}


template <>
class Matrix<int,3,3>{
public:
  int numberOfElements() const;
};

int Matrix<int,3,3>::numberOfElements() const {
  return 3*3;
}

int main(){

  std::cout << '\n';

  Matrix<double,10,5> matBigDouble;
  std::cout << "matBigDouble.numberOfElements(): " << matBigDouble.numberOfElements() << '\n';

  // Matrix matString;    // ERROR
  Matrix<> matString;
  std::cout << "matString.numberOfElements(): " << matString.numberOfElements() << '\n';

  Matrix<float> matFloat;
  std::cout << "matFloat.numberOfElements(): " << matFloat.numberOfElements() << '\n';

  Matrix<bool,20> matBool;
  std::cout << "matBool.numberOfElements(): " << matBool.numberOfElements() << '\n';

  Matrix <double,3,3> matSmallDouble;
  std::cout << "matSmallDouble.numberOfElements(): " << matSmallDouble.numberOfElements() << '\n';

  Matrix <int,3,3> matInt;
  std::cout << "matInt.numberOfElements(): " << matInt.numberOfElements() << '\n';

  std::cout << '\n';

}
