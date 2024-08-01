#include <initializer_list>

template <typename>
class TypeInfo;

int main() {

    auto a{1};
    auto b = {1, 2, 3};

    TypeInfo<decltype(a)> v;
    TypeInfo<decltype(b)> v2;
    
}