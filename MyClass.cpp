#include "MyClass.h"
#include <string>

template <typename T>
std::string MyClass<T>::getType() const {
    return typeid(T).name();
}

template class MyClass<int>; 