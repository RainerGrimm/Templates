#include <iostream>

template <typename T>
void showMe(const T& t){
  std::cout << t << '\n';
}

template <typename T>
struct ShowMe{
  explicit ShowMe(const T& t){
    std::cout << t << '\n';
  }
};

int main(){
  
  std::cout << '\n';
    
  showMe(5.5);          // not showMe<double>(5.5);
  showMe(5);            // not showMe<int>(5);
    
  ShowMe<double>(5.5);  // with C++17: ShowMe(5.5);
  ShowMe<int>(5);       // with C++17: ShowMe(5);
  
  std::cout << '\n';
    
}
