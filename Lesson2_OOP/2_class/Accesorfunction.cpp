#include <iostream>
#include <string>

class BankAccount {
private:
  // TODO: declare member variables
  int account_number{0};
  std::string owner_name = "no name";
  int available_funds = 0;

public:
  // TODO: declare setters
  void set_account_number(int number);
  void set_owner_name(std::string name);
  void set_available_funds(int funds);

  // TODO: declare getters
  int get_account_number();
  std::string get_owner_name();
  int get_available_funds();
};

// TODO: implement setters
void BankAccount::set_account_number(int number) { account_number = number; }
void BankAccount::set_owner_name(std::string name) { owner_name = name; }
void BankAccount::set_available_funds(int funds) { available_funds = funds; }

// TODO: implement getters
int BankAccount::get_account_number() { return account_number; }
std::string BankAccount::get_owner_name() { return owner_name; }
int BankAccount::get_available_funds() { return available_funds; }

int main() {
  // TODO: instantiate and output a bank account
  BankAccount BankAccount1;
  BankAccount1.set_account_number(123);
  BankAccount1.set_available_funds(100);
  BankAccount1.set_owner_name("kjs");

  std::cout << BankAccount1.get_account_number() << "\n";
  std::cout << BankAccount1.get_owner_name() << "\n";
  std::cout << BankAccount1.get_available_funds() << "$\n";
}