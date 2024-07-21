#include <iostream>

void g(double) { std::cout << "g(double)\n"; }
 
template<class T>
struct S {
    void f() const {
        g(1);              // non-dependent
    }
};
 
void g(int) { std::cout << "g(int)\n"; }
 
int main(){
    g(1);                 // calls g(int)
 
    S<int> s;
    s.f();                // calls g(double)
}
