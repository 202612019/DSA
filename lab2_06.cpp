/*
Given a positive integer N, write a recursive program to calculate and print the sum of its decimal digits.

For example, the sum of the digits of 5724 is:

5 + 7 + 2 + 4 = 18

Input Format

A single positive integer N.

Constraints

1 <= N <= 10^18

Output Format

Print a single integer representing the sum of the digits of N.

Sample Input 0

5724
Sample Output 0

18
Explanation 0

The digits of 5724 are:

5, 7, 2, and 4.

Their sum is:

5 + 7 + 2 + 4 = 18.

Hence the answer is 18.

Sample Input 1

1005
Sample Output 1

6
Explanation 1

The digits of 1005 are:

1, 0, 0, and 5.

Their sum is:

1 + 0 + 0 + 5 = 6.

Hence the answer is 6.
*/

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