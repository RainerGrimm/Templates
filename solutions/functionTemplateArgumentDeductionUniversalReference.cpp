// functionTemplateArgumentDeductionUniversalReference.cpp

template <typename T>
void funcUniversal(T&& param){}


int main(){
  
  int x = 2011;
  const int cx = x;
  const int& rx = x;
  
  funcUniversal(x);
  funcUniversal(cx);
  funcUniversal(rx);
  funcUniversal(2014);
  
}
