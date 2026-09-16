/*
2. Demonstrate the concept of polymorphism in C++ using an example of different payment
methods. Implement functions UPI(), CreditCard(), and NetBanking() to represent different
payment modes.
*/

#include <iostream>
#include <string>
using namespace std;

class PaymentSystem {
public:
    virtual void processPayment(double amount) {
        cout << "Processing a generic payment of Rs. " << amount << "\n";
    }
    
    virtual ~PaymentSystem() {} 
};

class UPI : public PaymentSystem {
public:
    void processPayment(double amount) override {
        cout << "Initiating UPI()... Payment of Rs. " << amount << " successful via UPI.\n";
    }
};

class CreditCard : public PaymentSystem {
public:
    void processPayment(double amount) override {
        cout << "Initiating CreditCard()... Payment of Rs. " << amount << " successful via Credit Card.\n";
    }
};

class NetBanking : public PaymentSystem {
public:
    void processPayment(double amount) override {
        cout << "Initiating NetBanking()... Payment of Rs. " << amount << " successful via Net Banking.\n";
    }
};

void executePayment(PaymentSystem* paymentMethod, double amount) {
    paymentMethod->processPayment(amount); 
}

int main() {
    cout << "--- Payment Gateway ---\n\n";

    UPI myUpi;
    CreditCard myCard;
    NetBanking myBank;

    executePayment(&myUpi, 500.0);
    executePayment(&myCard, 1250.50);
    executePayment(&myBank, 10000.0);

    return 0;
}