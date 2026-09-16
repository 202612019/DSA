/*
Given an integer N, generate and print the first N prime numbers in increasing order.

A prime number is an integer greater than 1 that has exactly two positive divisors: 1 and itself.

The solution must use iteration rather than recursion.

Input Format

The input consists of a single integer N.

Constraints

1 <= N <= 10000

Output Format

Print the first N prime numbers in increasing order, separated by spaces.

Sample Input 0

6
Sample Output 0

2 3 5 7 11 13
Explanation 0

The first six prime numbers are:

2, 3, 5, 7, 11, and 13.

Hence the output is:

2 3 5 7 11 13

Sample Input 1

1
Sample Output 1

2
Explanation 1

The first prime number is 2.

Hence the output is:

2
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    int num = 2;

    while (count < n) {
        bool isPrime = true;

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << num << " ";
            count++;
        }
        
        num++;
    }
    
    cout << "\n";
    return 0;
}