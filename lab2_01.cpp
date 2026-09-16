/*
Given an array of integers, find the second largest distinct element in the array.

The second largest distinct element is the largest value that is strictly smaller than the maximum element.

Duplicate values should be considered only once.

If the array contains fewer than two distinct elements, print -1.

Hints

Hint 1: You do not need to sort the array.

Hint 2: Traverse the array once while maintaining the largest and second largest distinct values.

Hint 3: Ignore duplicate values when updating the answer.

Expected Time Complexity: O(N) Expected Auxiliary Space: O(1)

Input Format

The first line contains an integer N, the number of elements.

The second line contains N space-separated integers.

Constraints

2 <= N <= 100000

-10^9 <= Ai <= 10^9

Output Format

Print the second largest distinct element.

If there are fewer than two distinct values, print -1.

Sample Input 0

6
12 35 1 10 34 1
Sample Output 0

34
Explanation 0

The distinct elements are:

1 10 12 34 35

The largest distinct element is 35.

The second largest distinct element is 34.

Hence the answer is 34.

Sample Input 1

4
7 7 7 7
Sample Output 1

-1
Explanation 1

The distinct elements are:

7

The largest distinct element is 7.

There is no second largest distinct element because the array contains only one distinct value.

Hence the answer is -1.
*/

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int largest = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        cout << -1 << endl;
    }
    else {
        cout << second << endl;
    }

    return 0;
}