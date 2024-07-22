template <typename T>
void funcValue(T param){}

int main(){
  
  int x = 2011;
  const int cx = x;
  const int& rx = x;
  
  funcValue(x);
  funcValue(cx);
  funcValue(rx);
  
}
