#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initial_balance) {
        if (initial_balance >= 0) {
            balance = initial_balance;
        } else {
            balance = 0;
            cout << "Invalid initial balance. Setting to 0.\n";
        }
    }

    void deposit(double amount) {
        if (amount >= 0) {
            balance += amount;
            cout << "Deposited: Rs. " << amount << "\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount >= 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: Rs. " << amount << "\n";
        } else if (amount > balance) {
            cout << "Transaction failed: Insufficient funds.\n";
        } else {
            cout << "Invalid withdrawal amount.\n";
        }
    }

    double get_balance() {
        return balance;
    }
};

int main() {
   double inputAmount;

    // 1. Input initial balance
    cout << "Enter your initial balance: Rs. ";
    cin >> inputAmount;
    BankAccount myAccount(inputAmount);

    // 2. Input deposit amount
    cout << "\nEnter amount to deposit: Rs. ";
    cin >> inputAmount;
    myAccount.deposit(inputAmount);

    // 3. Input first withdrawal amount
    cout << "\nEnter amount to withdraw: Rs. ";
    cin >> inputAmount;
    myAccount.withdraw(inputAmount);

    // 4. Input second withdrawal amount
    cout << "\nEnter another amount to withdraw: Rs. ";
    cin >> inputAmount;
    myAccount.withdraw(inputAmount);

    // Display final balance
    cout << "\nCurrent Balance: Rs. " << myAccount.get_balance() << "\n";

    return 0;
}