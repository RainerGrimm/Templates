// functionTemplateArgumentDeductionReference.cpp

template <typename T>
void func(T& param){}

template <typename T>
void constFunc(const T& param){}

int main(){
  
  int x = 2011;
  const int cx = x;
  const int& rx = x;
  
  func(x);
  func(cx);
  func(rx);
   
  constFunc(x);
  constFunc(cx);
  constFunc(rx);
  
}
