/*
You are given an integer array nums.

In one operation, you can either add 1 or subtract 1 from any element of the array.

Your task is to find the minimum number of operations required to make every element of nums divisible by 3.

Return the minimum number of operations.

For each number: - If it is already divisible by 3, it requires 0 operations. - Otherwise, determine the minimum number of +1 or -1 operations needed to make it divisible by 3.

Input Format

The first line contains an integer N, representing the number of elements in the array.

The second line contains N space-separated integers representing the array nums.

Constraints

1 ≤ N ≤ 50 1 ≤ nums[i] ≤ 50

Output Format

Print a single integer representing the minimum number of operations required.

Sample Input 0

4
1 2 3 4
Sample Output 0

3
Explanation 0

1 → 0 requires 1 operation
2 → 3 requires 1 operation
3 is already divisible by 3, so it requires 0 operations
4 → 3 requires 1 operation
Total operations = 1 + 1 + 0 + 1 = 3

Sample Input 1

3
3 6 9
Sample Output 1

0
Explanation 1

All elements are already divisible by 3, so no operations are required.
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++){
        if(((arr[i]+1) % 3==0)||((arr[i]-1) % 3==0)){
            count++;
        }
    }
    cout<<count;
    return 0;
}