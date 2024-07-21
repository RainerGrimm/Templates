#include <iostream>

void needInt(int i) {
    std::cout << i;
}

int main() {
	
    double d{1.234};
    needInt(d);
    
    bool b{true};
    needInt(true);
	
}
