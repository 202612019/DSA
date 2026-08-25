#include <iostream>
#include <cmath>

using namespace std;

int sumOfDigits(long long n) {

    if (n == 0) {
        return 0;
    }

    return (n % 10) + sumOfDigits(n / 10);
}

int main() {

    long long n;

    if (cin >> n) {
        cout << sumOfDigits(abs(n)) << "\n";
    }

    return 0;
}