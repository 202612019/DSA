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
    int arr2[n];

    int start = 0;
    int count = n - 1;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {

        if (arr[i] != 0) {
            arr2[start] = arr[i];
            start++;
        }
        else {
            arr2[count] = arr[i];
            count--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    
    return 0;
}


// #include <iostream>
// using namespace std;


// int main() {
   
//     int n;
//     cin >> n;


//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
   
//     int in_zero = 0;
   
//     for (int i = 0; i < n; ++i) {
//         if (arr[i] != 0) {
//             arr[in_zero] = arr[i];
//             in_zero++;
//         }
//     }
   
//     while (in_zero < n) {
//         arr[in_zero] = 0;
//         in_zero++;
//     }
   
//     for (int i = 0; i < n; ++i) {
//         cout << arr[i] << (i == n - 1 ? "" : " ");
//     }
//     cout << "\n";
     
//     return 0;
// }
