#include <concepts>
#include <iostream>     

template <std::regular T>
class MyVector{};


int main() {

    MyVector<int> myVec1;
    MyVector<int&> myVec2;

}