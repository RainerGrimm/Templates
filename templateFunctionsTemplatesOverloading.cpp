#include <iostream>

void xchg(int& x, int& y){   // 1
  int t= x;
  x=y;
  y=t;
}


template <typename T>        // 2
void xchg(T& x, T& y){
  T t= x;
  x=y;
  y=t;
}

template <typename T>         // 3
void xchg(T& x, T& y, T& z){
  xchg(x,y);
  xchg(x,z);
}


int main(){

  std::cout << '\n';

  int intA= 5;
  int intB= 10;
  int intC= 20;

  double doubleA= 5.5;
  double doubleB= 10.0;

  xchg(intA, intB);              // 1
  xchg(doubleA, doubleB);        // 2

  xchg<>(intA, intB);            // explicit 2
  xchg<int>(intA, intB);         // explicit 2: xchg<int>
  // xchg<double>(intA, intB);      // ERROR explicit xchg<double>

  xchg(intA, intB, intC);        // 3

  std::cout << '\n';

}
