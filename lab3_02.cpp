/*You are given an integer array nums sorted in non-decreasing order.

Your task is to remove the duplicate elements in-place so that each unique element appears only once.

The relative order of the elements must be preserved.

Return the number of unique elements in the array.

After removing duplicates, the first k positions of the array must contain the unique elements, where k is the number of unique elements.

Input Format

The first line contains an integer N, representing the number of elements in the array.

The second line contains N space-separated integers representing the sorted array nums.

Constraints

1 ≤ N ≤ 30000 -100 ≤ nums[i] ≤ 100 The array is sorted in non-decreasing order.

Output Format

Print a single integer k, representing the number of unique elements in the array.

Sample Input 0

10
0 0 1 1 1 2 2 3 3 4
Sample Output 0

5
Explanation 0

After removing duplicates, the first 5 elements of the array become:

0 1 2 3 4

Therefore, the number of unique elements is 5.

Sample Input 1

3
1 1 2
Sample Output 1

2
Explanation 1

After removing duplicates, the first 2 elements of the array become:

1 2

Therefore, the number of unique elements is 2.*/

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin>> n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(n==0){
        return 0;
    }
    
    int k = 1;

    for(int i=1; i<n; i++){
        if(arr[i]!= arr[i-1]){
            arr[k]= arr[i];
            k++;
        }
    }

    cout<<k;

    return 0;
}