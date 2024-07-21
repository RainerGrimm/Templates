#include <iostream>

template <typename T>
class Bank{
  std::string secret{"Import secret from the bank."};
  friend T;
};

class Account{
public:
  Account(){
    Bank<Account> bank;
    std::cout << bank.secret << '\n';
  }
};

int main(){

  std::cout << '\n';

  Account acc;

  std::cout << '\n';

}
