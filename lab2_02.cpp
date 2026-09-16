/*
Given an integer array, move all zero-valued elements to the end of the array while preserving the relative order of all non-zero elements.

The transformation should be performed in-place without changing the relative ordering of the non-zero values.

Input Format

The first line contains an integer N, the size of the array.

The second line contains N space-separated integers.

Constraints

1 <= N <= 100000

-10^9 <= Ai <= 10^9

Output Format

Print the modified array as N space-separated integers.

Sample Input 0

7
0 1 0 3 12 0 5
Sample Output 0

1 3 12 5 0 0 0
Explanation 0

The non-zero elements are 1, 3, 12, and 5. Their relative order remains unchanged, while all zero-valued elements are moved to the end of the array.

Sample Input 1

5
0 0 0 1 2
Sample Output 1

1 2 0 0 0
Explanation 1

The non-zero elements are 1 and 2. After moving all zero-valued elements to the end while preserving their order, the resulting array is:

1 2 0 0 0
*/

#include <iostream>
using namespace std;

int main() {
   
    int n;
    cin >> n;

    int arr[n];
   
    int sum = n * (n + 1) / 2;
    int actualSum = 0;
   
   for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
        actualSum += arr[i];
    }
   
   int missing = sum - actualSum;

    cout << missing << endl;
     
    return 0;
    
}