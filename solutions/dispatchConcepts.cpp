#include <concepts>
#include <iostream>

template <typename T>
concept Interface = requires(T a){
        { a.interface } -> std::convertible_to<bool>;
};

struct Base{
    virtual void interface(){
        std::cout << "Implementation Base" << '\n';
    }
};

struct Derived1: Base{
    virtual void interface(){
        std::cout << "Implementation Derived1" << '\n';
    }
};

struct Derived2: Base{
    virtual void interface(){
        std::cout << "Implementation Derived2" << '\n';
    }
};

struct Derived3: Base{};

template <typename Interface>
void execute(Interface& inter){
    inter.interface();
}

int main(){
    
    std::cout << '\n';
    
    Derived1 d1;
    execute(d1);
    
    Derived2 d2;
    execute(d2);
    
    Derived3 d3;
    execute(d3);
    
    std::cout << '\n';
    
}
