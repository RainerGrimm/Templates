So I think it's morning#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

template<typename T, typename Cont= std::vector<T> >
class MyVector{
  Cont cont;   

public:
  // MyVector with initial size
  explicit MyVector(const std::size_t n) : cont(n){}

  // MyVector with initial size and value
  MyVector(const std::size_t n, const double initialValue) : cont(n, initialValue){}

  // Constructor for underlying container
  explicit MyVector(const Cont& other) : cont(other){}

  // assignment operator for MyVector of different type
  template<typename T2, typename R2>
  MyVector& operator=(const MyVector<T2, R2>& other){
    assert(size() == other.size());
    for (std::size_t i = 0; i < cont.size(); ++i) cont[i] = other[i];
    return *this;
  }

  // size of underlying container
  std::size_t size() const{ 
    return cont.size(); 
  }

  // index operators
  T operator[](const std::size_t i) const{ 
    return cont[i]; 
  }

  T& operator[](const std::size_t i){ 
    return cont[i]; 
  }

  // returns the underlying data
  const Cont& data() const{ 
    return cont; 
  }

  Cont& data(){ 
    return cont; 
  }
};

template<template<typename> class Oper, typename T, typename Op1 , typename Op2>
class MyVectorCalc{
  const Op1& op1;
  const Op2& op2;
  Oper<T> oper;

public:
  MyVectorCalc(const Op1& a, const Op2& b): op1(a), op2(b) {}

  T operator[](const std::size_t i) const{ 
    
    return oper(op1[i], op2[i]); 
  }

  std::size_t size() const{ 
    return op1.size(); 
  }
};

// function template for the + operator
template<typename T, typename R1, typename R2>
MyVector<T, MyVectorCalc<std::plus, T, R1, R2> >
operator+ (const MyVector<T, R1>& a, const MyVector<T, R2>& b){
  return MyVector<T, MyVectorCalc<std::plus, T, R1, R2> >(MyVectorCalc<std::plus, T, R1, R2 >(a.data(), b.data()));  
}

// function template for the - operator
template<typename T, typename R1, typename R2>
MyVector<T, MyVectorCalc<std::minus, T, R1, R2> >
operator- (const MyVector<T, R1>& a, const MyVector<T, R2>& b) {
	return MyVector<T, MyVectorCalc<std::minus, T, R1, R2> >(MyVectorCalc<std::minus, T, R1, R2 >(a.data(), b.data()));
}

// function template for the * operator
template<typename T, typename R1, typename R2>
MyVector<T, MyVectorCalc<std::multiplies, T, R1, R2> >
operator* (const MyVector<T, R1>& a, const MyVector<T, R2>& b){
   return MyVector<T, MyVectorCalc<std::multiplies, T, R1, R2> >(MyVectorCalc<std::multiplies, T, R1, R2 >(a.data(), b.data()));
}

// function template for the / operator
template<typename T, typename R1, typename R2>
MyVector<T, MyVectorCalc<std::divides, T, R1, R2> >
operator/ (const MyVector<T, R1>& a, const MyVector<T, R2>& b) {
	return MyVector<T, MyVectorCalc<std::divides, T, R1, R2> >(MyVectorCalc<std::divides, T, R1, R2 >(a.data(), b.data()));
}

// function template for < operator
template<typename T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& cont){  
  std::cout << '\n';
  for (int i=0; i<cont.size(); ++i) {
    os << cont[i] << ' ';
  }
  os << '\n';
  return os;
} 

int main(){

  MyVector<double> x(10,5.4);
  MyVector<double> y(10,10.3);

  MyVector<double> result(10);
  
  result = x + x + y * y - x + x + y / y;
  
  std::cout << result << '\n';
  
}
