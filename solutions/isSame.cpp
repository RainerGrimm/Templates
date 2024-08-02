#include <type_traits>

template <typename T>
struct RemoveConst{    
  typedef T type;
};

template <typename T>
struct RemoveConst<const T>{    
  typedef T type;
};  

template <typename T, typename T2>
struct IsSame{    
  static bool const value = false;
};

template <typename T>
struct IsSame<T, T>{    
  static bool const value = false;
};

int main(){    

  std::is_same<int, RemoveConst<int>::type>::value;       
  std::is_same<int, RemoveConst<const int>::type>::value;  
  IsSame<int, RemoveConst<int>::type>::value;       
  IsSame<int, RemoveConst<const int>::type>::value;

}
