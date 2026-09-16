/*
Given a non-negative integer N, write a recursive program to calculate and print the N-th Fibonacci number.

The Fibonacci sequence is defined as:

F(0) = 0 F(1) = 1 F(N) = F(N - 1) + F(N - 2), for N ≥ 2

Input Format

A single non-negative integer N.

Constraints

0 <= N <= 40

Output Format

Print the N-th Fibonacci number.

Sample Input 0

7
Sample Output 0

13
Explanation 0

The Fibonacci sequence begins as:

0 1 1 2 3 5 8 13 ...

The 7th Fibonacci number is 13.

Sample Input 1

0
Sample Output 1

0
Explanation 1

By definition,

F(0) = 0.

Hence the answer is 0.
*/

#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    int n;
    cin >> n;
    cout << fibonacci(n) << "\n";
    return 0;
}