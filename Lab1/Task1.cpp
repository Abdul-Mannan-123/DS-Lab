#include <iostream>
using namespace std;

class BankAccount {
    int balance;
public:
    BankAccount() { 
		balance = 0;
	}
	
    BankAccount(int b) { 
		balance = b;
	 }
    BankAccount(const BankAccount& other) { 
		balance = other.balance; 
	}
    void deduct(int amount) { 
		balance -= amount;
	}
    int getBalance() { 
		return balance; 
	}
};

int main() {
    BankAccount account1;
    cout << account1.getBalance() << endl;

    BankAccount account2(1000);
    cout << account2.getBalance() << endl;

    BankAccount account3(account2);
    account3.deduct(200);
    cout << account3.getBalance() << endl;
    cout << account2.getBalance() << endl;

    return 0;
}
