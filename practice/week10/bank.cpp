#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
private:
    // private: 외부에서 직접 접근할 수 없음.
    // 잔액은 외부에서 직접 수정되지 않도록 private로 설정.
    double balance;
    string accountHolderName;

public:
    // public: 누구나 접근 가능. 생성자
    BankAccount(string name, double initialBalance)
    {
        accountHolderName = name;
        balance = initialBalance;
    }
    // 현재 잔액 조회 메서드
    double getBalance() const
    {
        return balance;
    }
    // 입금 메서드
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << amount << " deposited. Current balance: " << balance << endl;
        }
    }
    string getAccountHolderName() const
    {
        return accountHolderName;
    }
    void setAccountHolderName(const string &name)
    {
        accountHolderName = name;
    }
    // 출금 메서드
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << amount << " withdrawn. Current balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }
};
int main()
{
    BankAccount myAccount("Alice", 1000);
    cout << "Initial Balance: " << myAccount.getBalance() << endl;
    myAccount.deposit(500);
    myAccount.withdraw(200);
    // myAccount.balanceHolderName = "Bob";
    // myAccount.accountHolderName = "Bob";

    return 0;
}