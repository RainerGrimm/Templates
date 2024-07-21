#include <iostream>

class Account{
public:
  explicit Account(double b): balance(b){}
  double getBalance() const {
    return balance;
  }
private:
  double balance;
};

template <typename T, int Line, int Column>
class Matrix;


template <typename T>
class Matrix<T,3,3>{
  std::string name{"Partial Specialization"};
};

template <>
class Matrix<int,3,3>{};


template<typename T>
bool isSmaller(T fir, T sec);

template <>
bool isSmaller<Account>(Account fir, Account sec){
  return fir.getBalance() < sec.getBalance();
}

int main(){

  std::cout << std::boolalpha << '\n';

  // Matrix<double,3,4> primaryM;   // ERROR
  Matrix<double,3,3> partialM;
  Matrix<int,3,3> fullM;

 // std::cout << "isSmaller(3,4): "  << isSmaller(3,4) << '\n';  // ERROR
  std::cout << "isSmaller(Account(100.0),Account(200.0)): "<< isSmaller(Account(100.0),Account(200.0) ) << '\n';

  std::cout << '\n';

}
