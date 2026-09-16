/*
1. Find all Armstrong numbers between 100 and 2000. (An Armstrong number is a number whose
sum of its digits each raised to the power of the number of digits equals the number itself - for
example, 153=13+53+3
3)
*/

#include <iostream>
using namespace std;

int power(int base, int exp) {
    int res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

bool isArmstrong(int num) {
    int original = num;
    int temp = num;
    int Digits = 0;
    int sum = 0;

    while (temp > 0) {
        temp /= 10;
        Digits++;
    }

    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += power(digit, Digits);
        temp /= 10;
    }

    return sum == original;
}

int main() {
    cout << "Armstrong numbers between 100 and 2000:\n";

    for (int i = 100; i <= 2000; ++i) {
        if (isArmstrong(i)) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}