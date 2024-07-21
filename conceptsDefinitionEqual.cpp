#include <iostream>

template<typename T>
concept Equal = requires(T a, T b) {
    { a == b } -> std::convertible_to<bool>;
    { a != b } -> std::convertible_to<bool>;
};

bool areEqual(Equal auto a, Equal auto b){
  return a == b;
}

struct WithoutEqual{
  bool operator==(const WithoutEqual& other) = delete;
};

struct WithoutUnequal{
  bool operator!=(const WithoutUnequal& other) = delete;
};

int main() {
  
    std::cout << std::boolalpha << '\n';
    std::cout << "areEqual(1, 5): " << areEqual(1, 5) << '\n';
  
    /*
  
    bool res = areEqual(WithoutEqual(),  WithoutEqual());
    bool res2 = areEqual(WithoutUnequal(),  WithoutUnequal());
  
    */

    std::cout << '\n';
  
}
